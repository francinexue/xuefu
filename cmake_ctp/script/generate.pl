#!/usr/bin/env perl
# 使用说明，需要一个参数: Md或Td的头文件
if (@ARGV != 3) {
    print "需要指定Md或Td的头文件、生成的类名、生成文件的前缀\n";
    exit 1;
}
$headerFile = $ARGV[0];
$className = $ARGV[1];
$prefix = $ARGV[2];
#$success = open HEADERFILE, '<:encoding(UTF-8)', $headerFile;
$success = open HEADERFILE, '<:encoding(ISO-8859-1)', $headerFile;
if (! $success) {
    print "找不到指定文件$headerFile\n";
    exit 1;
}

open MACRO, '>:encoding(UTF-8)', "${prefix}_macro.txt";
#open HEADER, '>:encoding(UTF-8)', "${prefix}_header.txt";
open HEADER, '>:encoding(ISO-8859-1)', "${prefix}_header.txt";
open SOURCE, '>:encoding(UTF-8)', "${prefix}_source.txt";
open TASK, '>:encoding(UTF-8)', "${prefix}_task.txt";
open APIHEADER, '>:encoding(UTF-8)', "${prefix}_apiheader.txt";
open APISOURCE, '>:encoding(UTF-8)', "${prefix}_apisource.txt";
open WRAPPER, '>:encoding(UTF-8)', "${prefix}_${className}Wrap.txt";
open EXPORTER, '>:encoding(UTF-8)', "${prefix}_${className}Exporter.txt";
open PYCODE, '>:encoding(ISO-8859-1)', "${prefix}_pycode.txt";

print TASK "void ${className}::processTask() {\n";
print TASK "\twhile (true) {\n";
print TASK "\t\tTask* task = this->task_queue.wait_and_pop();\n";
print TASK "\t\tWithdrawGIL lock;\n";
print TASK "\t\tswitch (task->name) {\n";

print WRAPPER "struct ${className}Wrap : ${className}, wrapper<${className}> {\n";
print EXPORTER "\tclass_<${className}Wrap, boost::noncopyable>(\"${className}\")\n";

while(<HEADERFILE>) {
    chomp;
    $pre = $line;
    $line = $_;
    if ($line =~ /^(\s*virtual void\s+)(On\w+)\(/) {
        my $macro = $2;
        my $modifier = $1;
        my $func = $2;
        $macro =~ s/([A-Z])/_\1/g;
        $macro = substr(uc($macro), 1);
        print MACRO "#define $macro ", ++$count, "\n";

        my $start = index($line, '(');
        my $end = index($line, ')');
        print HEADER "$pre\n";
        print HEADER "$modifier$func", substr($line, $start, $end - $start + 1), ";\n";
        print HEADER "$modifier", lcfirst($func), "(";
        print SOURCE "void ${className}::$func", substr($line, $start, $end - $start + 1), " {\n";
        print SOURCE "\tTask *task = new Task();\n";
        print SOURCE "\ttask->name = $macro;\n";
        print TASK "\t\t\tcase $macro: {\n";
        print EXPORTER "\t\t.def(\"", lcfirst($func), "\", pure_virtual(&${className}Wrap::", lcfirst($func), "))\n";
        my $params = "", $funcParams = "", $pyFuncParams = "self";
        my $caller = "\t\t\t\tthis->" . lcfirst($func) . "(";
        while($start + 1 < $end) {
            my $comma = index($line, ',', $start + 1);
            if ($comma != -1) {
                $sub = substr($line, $start + 1, $comma - $start -1);
                $start = $comma;
            } else {
                $sub = substr($line, $start + 1, $end - $start - 1);
                $start = $end;
            }
            $sub =~ s/^\s+|\s+$//g;
            $sub =~ s/\s+$/ /g;
            my $asterisk = index($sub, '*');
            my $space = index($sub, ' ');
            my $type, $name, $pointer;
            if ($asterisk != -1) {
                $name = substr($sub, 0, $asterisk < $space ? $asterisk : $space);
                $name =~ s/^CThostFtdc//;
                $pointer = substr($sub, $asterisk > $space ? $asterisk + 1 : $space + 1);
                $funcParams .= "object &" . lcfirst($name);
                $pyFuncParams .= ", $name";
                $params .= lcfirst($name);
                if(index($name, "RspInfo") != -1) {
                    print SOURCE "\tif ($pointer)\n\t\ttask->resp = $name(*$pointer);\n";
                    print TASK "\t\t\t\tconst object &resp = task->resp.empty() ? object() : object(any_cast<$name &>(task->resp));\n";
                    $caller .= "const_cast<object &>(resp)";
                } else {
                    print SOURCE "\tif ($pointer)\n\t\ttask->payload = $name(*$pointer);\n";
                    print TASK "\t\t\t\tconst object &payload = task->payload.empty() ? object() : object(any_cast<$name &>(task->payload));\n";
                    $caller .= "const_cast<object &>(payload)";
                }
            } else {
                $type = substr($sub, 0, $space);
                $name = substr($sub, $space + 1);
                if ($type eq "int") {
                    print SOURCE "\ttask->num = $name;\n";
                    $caller .= "task->num";
                } else {
                    print SOURCE "\ttask->final = $name;\n";
                    $caller .= "task->final";
                }
                if ($name eq "nRequestID") {
                    $name = "requestId";
                } elsif ($name eq "bIsLast") {
                    $name = "final";
                } elsif ($name eq "nReason") {
                    $name = "reasonCode";
                } elsif ($name eq "nTimeLapse") {
                    $name = "lapsedTime";
                }
                $funcParams .= "$type $name";
                $pyFuncParams .= ", $name";
                $params .= "$name";
            }

            if ($comma != -1) {
                $params .= ", ";
                $funcParams .= ", ";
                $caller .= ", ";
            }
        }
        print HEADER "$funcParams) {};\n\n";
        print SOURCE "\tthis->task_queue.push(task);\n}\n\n";
        print TASK "$caller);\n\t\t\t\tbreak;\n\t\t\t}\n";
        print PYCODE "\tdef ", lcfirst($func), "(", $pyFuncParams, "):\n";
        my $comment = $pre;
        $comment =~ s/^\s*\/+//;
        print PYCODE "\t\t\"\"\"$comment\"\"\"\n";
        print PYCODE "\t\tpass\n";
        print PYCODE "\n\n";
        print WRAPPER "\n$modifier", lcfirst($func), "($funcParams) {\n";
        print WRAPPER "\t\ttry {\n";
        print WRAPPER "\t\t\tthis->get_override(\"", lcfirst($func), "\")($params);\n";
        print WRAPPER "\t\t} catch (error_already_set const &) {\n";
        print WRAPPER "\t\t\tPyErr_Print();\n";
        print WRAPPER "\t\t}\n\t};\n";
    } elsif ($line =~ /^\s*virtual\s+(.*)\s+(\*?)(\w+)\(/) {
        my $modifier = $1;
        my $func = $3;
        print APIHEADER "$modifier $2", lcfirst($func), "(";
        print APISOURCE "$modifier $2${className}::", lcfirst($func), "(";
        print EXPORTER "\t\t.def(\"", lcfirst($func), "\", &${className}Wrap::", lcfirst($func), ")\n";
        my $start = index($line, '(');
        my $end = index($line, ')');
        my $funcParams = "";
        my $count = 0;
        my $converter = "";
        my $caller;
        if ($modifier =~ /^void/) {
            $caller = "\tthis->api->" . $func . "(";
        } else {
            $caller = "\treturn this->api->" . $func . "(";
        }
        while($start + 1 < $end) {
            my $comma = index($line, ',', $start + 1);
            if ($comma != -1) {
                $sub = substr($line, $start + 1, $comma - $start -1);
                $start = $comma;
            } else {
                $sub = substr($line, $start + 1, $end - $start - 1);
                $start = $end;
            }
            $sub =~ s/^\s+|\s+$//g;
            $sub =~ s/\s+$/ /g;
            my $asterisk = index($sub, '*');
            my $space = index($sub, ' ');
            my $type, $name, $pointer;
            if ($asterisk != -1) {
                $name = substr($sub, 0, $asterisk < $space ? $asterisk : $space);
                $name =~ s/^CThostFtdc//;
                $pointer = substr($sub, $asterisk > $space ? $asterisk + 1 : $space + 1);
                if ($name eq "char") {
                    $pointer =~ s/^p//;
                    my $left = index($pointer, '[');
                    if ($left == -1) {
                        $funcParams .= "const std::string &$pointer";
                        $caller .= "const_cast<char *>($pointer.c_str())";
                    } else {
                        $pointer = substr($pointer, 0, $left) . "s";
                        $pointer =~ s/^p//;
                        $funcParams .= "list &" . lcfirst($pointer);
                        $converter .= "\tint length = len(" . lcfirst($pointer) . ");\n";
                        $converter .= "\tchar **array = new char*[length];\n";
                        $converter .= "\tfor (int i = 0; i < length; i++) {\n";
                        $converter .= "\t\t*(array + i) = const_cast<char *>(extract<const char *>(" . lcfirst($pointer) . "[i])());\n";
                        $converter .= "\t};\n";
                        $converter .= "\t//TODO please delete the pointer.\n";
                        $caller .= "array, length";
                        last;
                    }
                } else {
                    $funcParams .= "object &" . lcfirst($name);
                    $converter .= "\t$name *p" . (++$count) . " = extract<$name *>(" . lcfirst($name) . ");\n";
                    #$converter .= "//\t\t$name *p" . ($count) . " = NULL;\n";
                    #$converter .= "//\t\tif (!" . lcfirst($name) . ".is_none()) {\n";
                    #$converter .= "//\t\t\textract<$name *> tmp(" . lcfirst($name) . ");\n//\t\t\tif (tmp.check()) {\n//\t\t\t\tp$count = v();\n//\t\t\t}\n";
                    #$converter .= "//\t\t}\n\n";
                    $caller .= "p$count";
                }
            } else {
                $type = substr($sub, 0, $space);
                $name = substr($sub, $space + 1);
                if ($name eq "nRequestID") {
                    $name = "requestId";
                } elsif ($name eq "bIsLast") {
                    $name = "final";
                } elsif ($name eq "nReason") {
                    $name = "reasonCode";
                } elsif ($name eq "nTimeLapse") {
                    $name = "lapsedTime";
                }
                $funcParams .= "$type $name";
                $caller .= "$name";
            }

            if ($comma != -1) {
                $funcParams .= ", ";
                $caller .= ", ";
            }
        }

        print APIHEADER "$funcParams);\n\n";
        print APISOURCE "$funcParams) {\n"; 
        #print APISOURCE "\tif (this->api) {\n";
        print APISOURCE "$converter";
        print APISOURCE "$caller);\n";
        #print APISOURCE "\t}\n";
        print APISOURCE "}\n\n";
    }
}

print TASK "\t\t}\n\t\tdelete task;\n\t}\n}\n\n";
print WRAPPER "};\n";
print EXPORTER "\t\t;\n";

close HEADERFILE;
close MACRO;
close HEADER;
close SOURCE;
close TASK;
close APIHEADER;
close APISOURCE;
close WRAPPER;
close EXPORTER;


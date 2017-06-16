#!/usr/bin/env perl
# 使用说明，需要两个参数:
# 第一个参数是ThostFtdcUserApiDataType.h
# 第二个参数是ThostFtdcUserApiStruct.h
$typeFile = @ARGV ? $ARGV[0] : "ThostFtdcUserApiDataType.h";
$structFile = @ARGV ? $ARGV[1] : "ThostFtdcUserApiStruct.h"; 
#$success = open TYPEFILE, '<:encoding(UTF-8)', $typeFile;
$success = open TYPEFILE, '<:encoding(ISO-8859-1)', $typeFile;
if (! $success) {
    print "找不到指定文件$typeFile\n";
    exit 1;
}
while(<TYPEFILE>) {
    chomp;
    $line = $_;
    if ($line =~ /^typedef (\w+) TThostFtdc(\w+)Type(\[\d+\])?;$/) {
        $types{$2} = $1 . ($3 ? "[]" : "");
    }
}
close TYPEFILE;
#$success = open STRUCTFILE, '<:encoding(UTF-8)', $structFile;
$success = open STRUCTFILE, '<:encoding(ISO-8859-1)', $structFile;
if (! $success) {
    print "找不到指定文件$structFile\n";
    exit 1;
}
while(<STRUCTFILE>) {
    chomp;
    $line = $_;
    if ($line =~ /^struct\s+CThostFtdc(\w+)$/) {
        $struct=$1;
        print "\tclass_<$1>(\"$1\")";
    } elsif ($line =~ /^};$/) {
        $struct="";
        print ";\n\n";
    } elsif ($line =~ /^\s+TThostFtdc(\w+)Type\s(\w+);$/) {
        $type = $1;
        $property = $2;
        $name = $property;
        if (length($name) > 1) {
            $first = substr($name, 1, 1);
#            $upper = uc($first);
            if ($first ne uc($first)) {
                $name = lcfirst($name);
            }
        }
#        (my $name = $property) =~ s/(\w+)/\l$1/;
        if ($types{$type} eq "char[]") {
            print "\n\t\t.add_property(\"$name\", &${struct}::get$property, &${struct}::set$property)"; 
        } else {
            print "\n\t\t.def_readwrite(\"$name\", &${struct}::$property)";
        }
    } else {
    }
}
close STRUCTFILE;
#/^struct\s\+CThostFtdc\w\+$/,/^}$/ {
    #s/^\s\+TThostFtdc\(\w\+\)Type\s\(\w\+\);$/.add_property("\2", \&\1::get\2, \&\1::set\2)\n}/
    #/^struct\s\+CThostFtdc\w\+$/{
        #N
        #s/^struct\s\+CThostFtdc\(\w\+\)\n{/class_<\1>("\1")\n/
    #}
    #s/^}$/;/
#}

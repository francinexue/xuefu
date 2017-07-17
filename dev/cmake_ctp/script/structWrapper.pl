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
        $types{$2} = $1 . ($3 ? "[]" : "") ;
    }
}
close TYPEFILE;
#$success = open STRUCTFILE, '<:encoding(UTF-8)', $structFile;
$success = open STRUCTFILE, '<:encoding(ISO-8859-1)', $structFile;
if (! $success) {
    print "找不到指定文件$structFile\n";
    exit 1;
}

#@initToZeroFields = qw(InputOrderField InputOrderActionField);
while(<STRUCTFILE>) {
    chomp;
    $line = $_;
    if ($line =~ /^struct\s+CThostFtdc(\w+)$/) {
        $struct = $1;
        #if (grep { $struct eq $_ } @initToZeroFields) {
            print "struct $1: CThostFtdc$1 {\n\n\t$1() {\n\t\tstd::memset(this, 0, sizeof($1));\n\t}\n\n\t$1(const CThostFtdc$1& f): CThostFtdc$1(f){}\n\n\t$1& operator=(const CThostFtdc$1& f) {\n\t\tCThostFtdc$1::operator=(f);\n\t\treturn *this;\n\t}\n";
        #} else {
            #print "struct $1: CThostFtdc$1 {\n\n\t$1() {}\n\n\t$1(const CThostFtdc$1& f): CThostFtdc$1(f){}\n\n\t$1& operator=(const CThostFtdc$1& f) {\n\t\tCThostFtdc$1::operator=(f);\n\t}\n";
        #}
    } elsif ($line =~ /^{$/) {
        if (not $struct) {
            print "$line\n";
        }
    }elsif ($line =~ /^\s+TThostFtdc(\w+)Type\s(\w+);$/) {
        if ($types{$1} eq 'char[]') {
            print "\n\tvoid set$2(std::string v) {\n\t\tstd::copy(v.begin(), v.end(), this->$2);\n\t\tthis->${2}[v.size()] = '\\0';\n\t}\n\tconst char* get$2() {\n\t\treturn this->$2;\n\t}\n";
        }
    } elsif ($line =~ /^};$/) {
        if ($struct) {
            $struct=""
        }
        print "$line\n\n";
    } elsif ($line =~ /^\s+\/\/\/.+/) {
        #去掉字段的注释
    } else {
        if ($struct) {
            print "$line\n";
        }
    }
}
close STRUCTFILE;
#s/^\s\+TThostFtdc\(\w\+\)Type\s\(\w\+\);$/void set\2(std::string v){\nstd::copy(v.begin(), v.end(), (char *)\&(this->\2));\n*((char *)\&(this->\2) + v.size()) = '\\0';\n}\n\nconst char* get\2() {\nreturn (const char *)\&(this->\2);\n}/
#/^struct\s\+CThostFtdc\w\+$/{
    #N
    #s/^struct\s\+CThostFtdc\(\w\+\)\n{/struct \1: CThostFtdc\1 {\n\1() {}\n\1(const CThostFtdc\1\& f): CThostFtdc\1(f){}\n\1\& operator=(const CThostFtdc\1\& f) {\nCThostFtdc\1::operator=(f);\n}/
#}

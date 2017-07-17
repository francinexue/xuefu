#!/usr/bin/env perl
# 使用说明，需要两个参数:
# 第一个参数是wrapper.txt
# 第二个参数是field.txt
$wrapperFile = @ARGV ? $ARGV[0] : "wrapper.txt";
$fieldFile = @ARGV ? $ARGV[1] : "field.txt";
$success = open FIELDFILE, '<:encoding(UTF-8)', $fieldFile;
#$success = open FIELDFILE, '<:encoding(ISO-8859-1)', $fieldFile;
if (! $success) {
    print "找不到指定文件$fieldFile\n";
    exit 1;
}
while(<FIELDFILE>) {
    chomp;
    $line = $_;
    if (! $line =~ /^\s*$/) {
        push @fields, $line;
    }
}
close FIELDFILE;
#$success = open WRAPPERFILE, '<:encoding(UTF-8)', $wrapperFile;
$success = open WRAPPERFILE, '<:encoding(ISO-8859-1)', $wrapperFile;
if (! $success) {
    print "找不到指定文件$wrapperFile\n";
    exit 1;
}

while(<WRAPPERFILE>) {
    chomp;
    $line = $_;
    if ($line =~ /^\s*struct\s/) {
        foreach my $field (@fields) {
            if ($ok) {
                break;
            }
            if ($line =~ /^\s*struct\s+\Q${field}\E[:\s]/) {
                $ok = 1;
            }
        }
    } elsif ($line =~ /^\s*};$/) {
        if ($ok) {
            print $line, "\n\n";
            $ok = 0;
        }
    }
    if ($ok) {
        print $line, "\n";
    }
}
close WRAPPERFILE;

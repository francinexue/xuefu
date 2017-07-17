#!/usr/bin/env perl
# 使用说明，需要两个参数:
# 第一个参数是exporter.txt
# 第二个参数是field.txt
$exporterFile = @ARGV ? $ARGV[0] : "exporter.txt";
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
$success = open EXPORTERFILE, '<:encoding(UTF-8)', $exporterFile;
#$success = open EXPORTERFILE, '<:encoding(ISO-8859-1)', $exporterFile;
if (! $success) {
    print "找不到指定文件$exporterFile\n";
    exit 1;
}

while(<EXPORTERFILE>) {
    chomp;
    $line = $_;
    if ($line =~ /^\s*class_</) {
        foreach my $field (@fields) {
            if ($ok) {
                break;
            }
            if ($line =~ /^\s*class_<\Q$field>/) {
                $ok = 1;
            }
        }
    } elsif ($line =~ /^\s*$/) {
        if ($ok) {
            print "\n";
            $ok = 0;
        }
    }
    if ($ok) {
        print $line, "\n";
    }
}
close EXPORTERFILE;


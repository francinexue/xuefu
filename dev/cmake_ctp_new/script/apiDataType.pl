#!/usr/bin/env perl
while(<>) {
    chomp;
    $line = $_;
    if ($line =~ /^typedef (\w+) TThostFtdc(\w+)Type(\[\d+\])?;$/) {
        print $1, $3?"[]":"", "\t$2\n";
    }
}

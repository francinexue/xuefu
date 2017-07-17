#!/bin/bash
sed '/^\s*\//d' ${1:-/dev/stdin} | tr -s ' ;,{}\n():\t=' '\n' | sort | uniq | grep "^CThostFtdc" | sed 's/^CThostFtdc//'

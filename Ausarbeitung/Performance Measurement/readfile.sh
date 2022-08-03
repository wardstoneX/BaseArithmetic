#!/bin/bash
filename=$1
n=1
while read line; do
$line  >> output.txt
n=$((n+1))
done < $filename

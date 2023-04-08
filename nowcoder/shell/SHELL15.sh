#!/bin/bash

while read line
do
    if [[ $line =~ [Bb] ]]; then
        continue
    else
        echo $line
    fi
done < nowcoder.txt

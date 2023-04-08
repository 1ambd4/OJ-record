#!/bin/bash

cnt=0

while read line
do
    ((cnt++))
    if [ ! -z "$line" ]; then
        echo $line
    fi
done < nowcoder.txt

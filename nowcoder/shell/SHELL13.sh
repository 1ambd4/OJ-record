#!/bin/bash

while read line
do
    # 正则的语法糖么
    if [[ $line =~ "this" ]]; then
        continue
    else
        echo $line
    fi
done < nowcoder.txt

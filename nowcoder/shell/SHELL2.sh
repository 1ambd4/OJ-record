#!/bin/bash

cnt=0

while read line
do
    ((cnt++))
done < nowcoder.txt

while read line
do
    # 方括号前后都要加空格
    if [ $cnt -lt 6 -a $cnt -gt 0 ]
    then
        echo $line
    fi
    ((cnt--))
done < nowcoder.txt

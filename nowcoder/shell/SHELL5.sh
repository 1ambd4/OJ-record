#!/bin/bash

cnt=0

while read line
do
    ((cnt++))
    # if [ "$line" = "" ]
    # if [ ! "$line"  ]
    if [ -z "$line" ]
    then
        echo $cnt
    fi
done < nowcoder.txt

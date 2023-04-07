#!/bin/bash

# 等号前后千万不要加空格
cnt=0
while read line
do
    ((cnt++))
done < nowcoder.txt

echo $cnt

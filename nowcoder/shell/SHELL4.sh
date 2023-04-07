#!/bin/bash

# 等号两边加空格会奇怪打印出第六行
# 大概是初值1没赋上，被初始化成0了
cnt=0
while read line
do
    ((cnt++))
    if [ $cnt -eq 5 ]
    then echo $line
    fi
done < nowcoder.txt

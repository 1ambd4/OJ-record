#!/bin/bash

sum=0

read len
for ((i=0; i<$len; i++))
do
    read num
    ((sum+=$num))
done

# SHELL里似乎没浮点数？只能靠bc了啊
echo "scale=3;$sum/$len" | bc

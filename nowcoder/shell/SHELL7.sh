#!/bin/bash

read line < nowcoder.txt
for word in $line
do
    if [ "${#word}" -lt 8 ]; then
        echo "${word}"
    fi
done

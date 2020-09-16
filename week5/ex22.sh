#!/bin/bash

N=5

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex22.txt

for (( i = 1; i <= $N; i++ ))
do
	./add_lock.sh ex22.txt&
	./add_lock.sh ex22.txt
done

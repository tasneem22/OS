#!/bin/bash

N=4

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex21.txt

for (( i = 1; i <= $N; i++ ))
do
	# race condition usually took place after 5 increments
	./increase.sh ex21.txt&
	./increase.sh ex21.txt
done

# !/bin/bash

for ((i=1;i<=$1;i++))
do
	grep i $0 > i.out
done
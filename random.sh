#!/bin/bash
while ((i<10))
do
   N=$((RANDOM*1000000/32768))$((RANDOM*1000000/32768))
   echo "${A[*]}" | grep $N && continue # if number already in the array
   ((i++))
    echo "$i" # Monitoring purpose
done
# Display the array:
for ((i=0; i<${#A[@]}; i++))
do
   echo ${A[$i]}
done
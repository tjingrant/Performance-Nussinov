#!/bin/bash
make plain
time=0.0
for i in {1..10}
do
  result=$(./Nussinov 500 | egrep '[-+]?([0-9]*\.[0-9]+|[0-9]+)' -o)
  time=$(echo "$time+$result"| bc -l )
done

time+="/10"
time=$(echo "$time" | bc -l )
echo "Average time taken: $time"

name="./results/"
name+=$(date +"%m-%d-%y-%H_%M_%S")
name+=".result"

if [ "$1" = "-check" ]; then
    echo "$time" > "$name"
fi

if [ "$1" = "-compare" ]; then
    value="scale=2;100.0*($time-"
    value+=$(<"$2")
    value+=")/"
    value+=$(<"$2")
    value=$(echo "$value" | bc -l) 
    echo "Performance Difference: $value%"
fi

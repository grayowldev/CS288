#!/bin/sh

cd hwTesting

smallestNumber=0
largestNumber=0
array=()
argc=$#
#echo $argc
if [[ $argc -eq 0 ]]; then
  echo Please Enter At Least One Numerical Argument
elif [[ $argc -eq 1 ]]; then
  count=$( ls $1* 2>/dev/null| wc -l)
  array+=( $count )
else

  #Getting the smallest and largest number
  smallestNumber=$1
  largestNumber=$1
  for i in "$@"; do
    if [[ $i -eq $smallestNumber ]]; then
      continue
    elif [[ $i -lt $smallestNumber ]]; then
      smallestNumber=$i
    elif [[ $i -gt $largestNumber ]]; then
      largestNumber=$i
    fi
  done
  #echo $smallestNumber
  #echo $largestNumber
  for (( i = $smallestNumber; i < $largestNumber+1; i++ )); do
    count=$( ls $i* 2>/dev/null| wc -l)
    array+=( $count )
  done
fi

#printing array
for (( i = $smallestNumber; i < $largestNumber+1; i++ )); do
  echo $i ${array[i]}
done

#!/bin/sh
cd ../testdir

i=1
for name in *
do
  a=$( printf "%03d" $i )
  mv $name $1$a.$2
  (( ++i ))
done

ls

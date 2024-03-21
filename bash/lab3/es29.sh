#!/bin/bash

usage() {
  echo "usage: $0 dirname"
  exit 1
}

if [ "$#" -ne 1 ]; then
  usage
fi 

files=0
dirs=0 


cd "$1" || usage

for fname in *; do
  if [ -f "$fname" ]; then
    echo "F $fname"
    ((files+=1))
  elif [ -d "$fname" ]; then 
    echo "D $fname"
    ((dirs+=1))
  fi
done

echo "$files files"
echo "$dirs directories"

exit 0

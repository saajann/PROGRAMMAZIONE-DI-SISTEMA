#!/bin/bash

echo "$1"
while [ "$#" -ne 1 ]; do
  shift
done 
echo "$1"

exit 0

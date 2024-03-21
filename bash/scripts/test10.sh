#!/bin/bash

for fname in ./*; do
  if [ -f "$fname" ]; then
    echo "F $fname"
  elif [ -d "$fname" ]; then
    echo "D $fname"
  fi
done

exit 0 

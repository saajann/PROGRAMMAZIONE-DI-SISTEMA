#!/bin/bash

usage() {
  echo "usage: $0 dirname"
  exit 1  
}

cerca() {
  for i in "$1"/*; do
    echo "[$2] $i"
    if [ -d "$i" ]; then
      ((liv=$2+1))
      cerca "$i" "$liv"
    fi
  done
}

[ "$#" -ne 1 ] && usage
case "$1" in 
  /*) 
    if [ ! -d "$1" ]; then
      usage
    fi
    ;;
  *)
    usage
    ;;
esac
echo "[0] $1"
cerca "$1" 1

exit 0

#!/bin/bash

usage() {
  echo "usage: $0 dirname(abs) string n1 n2 "
  exit 1
}

search() {
  for i in "$1"/*; do
    if [ -f "$i" ] && [[ "$2" == "$i" ]]; then 
      echo "$i"
    fi
  done
}

[ "$#" -ne 4 ] && usage

case "$1" in 
  /*)
    if [ ! -n "$2" ]; then
      usage
    fi 
    if [ "$3" -lt 0 ] || [ "$4" -lt 0 ]; then
      usage
    fi
    ;;
  *)
    usage
    ;;
esac

search "$1" "$2" "$3" 

exit 0

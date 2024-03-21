#!/bin/bash

usage() {
  echo "usage: $0 dirname seconds"
  exit 1
}

if [ "$#" -ne 2 ] || [ ! -d "$1" ] || [ ! "$2" -gt 0 ]; then
  usage
fi

F_prev=0
D_prev=0
while true; do 
  F=0
  D=0
  for i in "$1"/*; do
    if [ -f "$i" ]; then
      ((F+=1))
    elif [ -d "$i" ]; then
      ((D+=1))
    fi
  done
  if [ "$F" -ne "$F_prev" ] || [ "$D" -ne "$D_prev" ]; then
    echo "Il numero di file / directory è cambiato"
    date   
  fi 
  ((F_prev=F))
  ((D_prev=D))
  sleep "$2"
done

exit 0

#!/bin/bash

[ "$#" -ne 2 ] && echo "inserisci 2 parametri, non $#" && exit 1

if [ -d "$1" ] && [ -w "$1" ]; then
  cd "$1"
  pwd > "$2"
else
  echo "il primo file non è una dir o non è scrivibile" 
fi 
exit 0

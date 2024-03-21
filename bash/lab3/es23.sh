#!/bin/bash

[ "$#" -ne 1 ] && echo "inserisci 1 parametro, non $#" && exit 1 

if [ -d "$1" ] && [ -r "$1" ]; then
  echo "il file è una directory esistente e leggibile nel filesystem"
else
  echo "errore"
fi 

exit 0

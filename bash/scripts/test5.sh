#!/bin/bash

case "$1" in
  /*) 
    echo "Percorso assoluto"
    ;;
  */*) 
    echo "Percorso relativo"
    ;;
  *) 
    echo "Nome semplice di file"
    ;;
esac

if [ ! -d "$1"] || [ ! -x "$1" ]; then
  echo "errore"
fi

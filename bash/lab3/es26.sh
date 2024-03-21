#!/bin/bash

usage() {
  echo "usage: $0 arg1"
  exit 1
}

if [ "$#" -ne 1 ]; then
  usage
fi

case "$1" in 
  /*)
    echo "percorso assoluto"
    ;;
  */*) 
    echo "percorso relativo"
    ;;
  *)
    echo "percorso relativo semplice"
    ;;
esac

exit 0  

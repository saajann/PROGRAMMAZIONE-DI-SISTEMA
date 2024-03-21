#!/bin/bash

case "$1" in 
  /*)
    echo "percorso assoluto"
    ;;

  */*)
    echo "percorso relativo"
    ;;
  
  *)
    if [ -f "$1" ]; then
      echo "nome file"
    else 
      echo "nome directory"
    fi
    ;;
esac

exit 0

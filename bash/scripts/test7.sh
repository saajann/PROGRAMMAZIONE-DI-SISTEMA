#!/bin/bash

case "$1" in
  
  ''|*[!0-9]*)
    echo "non è un numero"
    ;;
  
  *)
    echo "è un numero"
    ;;
esac

exit 0

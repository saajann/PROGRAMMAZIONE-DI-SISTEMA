#!/bin/bash

uscita() {
  echo "devi inserire 1 parametro"
  exit 1
}

[ "$#" -ne 1 ] && uscita

touch "$1".sh
chmod 755 "$1".sh
nano "$1".sh

exit 0



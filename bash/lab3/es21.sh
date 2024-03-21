#!/bin/bash

error() {
  echo "il numero dei parametri non corrisponde a 2"
  exit 1
}

[ ! "$#" -eq 2 ] && error
touch "$1"
chmod "$2" "$1"

exit 0

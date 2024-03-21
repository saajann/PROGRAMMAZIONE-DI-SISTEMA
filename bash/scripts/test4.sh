#!/bin/bash

if grep root /etc/passwd >/dev/null 2>&1; then
  echo "root trovato"
fi


exit 0

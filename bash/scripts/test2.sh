#!/bin/bash

grep $1 /etc/passwd
echo $?

exit 0

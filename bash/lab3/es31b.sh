#!/bin/bash

find "$1" -type d -printf "[%d] %p\n"

exit 0

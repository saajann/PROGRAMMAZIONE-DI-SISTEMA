#!/bin/bash

usage() {
    echo "usage: $0 absdir simplefile"
    exit 1
}

[ "$#" -ne 2 ] && usage

case "$1" in
    /*) [ ! -d "$1" ] || [ ! -x "$1" ] && usage
        ;;
    *) usage
        ;;
esac

case "$2" in 
    /*) usage
        ;;
    *) 
        ;;
esac

files=$(find "$1" -type f -name "$2" 2>/dev/null)
for file in $files; do
    echo "-----> $file"
    head -n 1 "$file"
    tail -n 2 "$file"
done

exit 0
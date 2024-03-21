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
created=1
for file in $files; do
    ln -s "$file" /tmp/link_$created
    created=$(( created + 1 ))
done

exit 0
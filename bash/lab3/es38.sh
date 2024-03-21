#!/bin/bash

usage() {
    echo "usage: $0 absdir simplefile simplefile"
    exit 1
}

[ "$#" -ne 3 ] && usage

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

case "$3 in 
    /*) usage
        ;;
    *) 
        ;;
esac

dirs=$(find "$1" -type d 2>/dev/null)
for dir in $dirs; do
    if [ -f "$dir"/"$2"] && [ -f "$dir"/$3"]; then
        f1="$dir"/"$2"
        f2="$dir"/"$3"
        if [ -r "$f1" ] && [ -r "$f2" ]; then
            echo "$dir"
            size_f1=$(ec -c < "$f1")
            size_f2=$(ec -c < "$f2")
            echo "$dir :" $(( size_f1 + size_f2 ))
        fi
    fi
done

exit 0
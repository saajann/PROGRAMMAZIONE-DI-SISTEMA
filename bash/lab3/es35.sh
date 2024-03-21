#!/bin/bash

usage() {
    echo "usage: $0 absdir n>0"
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
    ''|*[!0-9]*) usage
        ;;
    *) [ "$2" -le 0 ] && usage
        ;;
esac

dirs=$(find "$1" -type d 2>/dev/null)
for dir in $dirs; do
    files=$(find "$dir" -type f -readable 2>/dev/null)
    found=0
    for file in "$files"; do
        filesize=$(wc -c < "$file")
        [ "$filesize" -gt "$2" ] && found=$(( found + 1) )
    done
    if [ "$found" -gt 0]; then
        echo "$dir $found"
    fi
done

exit 0

# da invocare così
# $ ./es35.sh /etc 0 | sort -n
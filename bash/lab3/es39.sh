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

f1_count=0
f2_count=0

# versione alternativa
# f1_count=$(find "$1" -name "$2" 2>/dev/null | wc -l)
# f2_count=$(find "$1" -name "$3" 2>/dev/null | wc -l) 


dirs=$(find "$1" -type d 2>/dev/null)
for dir in $dirs; do
    f1="$dir"/"$2"
    f2="$dir"/"$3"
    [ -f "$f1" ] && f1_count=$(( f1_count + 1 ))
    [ -f "$f2" ] && f2_count=$(( f2_count + 1 ))
done

echo "$f1_count"
echo "$f2_count"

exit 0
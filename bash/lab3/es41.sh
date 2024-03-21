#!/bin/bash

usage() {
    echo "usage: $0 [-h] -d dirname -m EQ|NE"
    exit 1
}

while getopts "d:m:h" o; do
    case "$o" in 
        d) D="$OPTARG"
            case "$D" in 
                /*) [ ! -d "$D" ] || [ ! -x "$D" ] && usage
                    ;;
                *) usage
            esac 
            ;;
        m) M="$OPTARG"
            case "$M" in
                EQ|NE)
                    ;;
                *) usage
                    ;;
            esac
            ;;
        h) usage  
            ;;
        *) usage
            ;;
    esac
done

shift $(( OPTIND - 1 ))

dirs=$(find "$D" -type d 2>/dev/null)
for dir in $dirs; do
    f_count=$(find "$dir" -maxdepth 1 -type f 2>/dev/null| wc -l)
    d_count=$(find "$dir" -maxdepth 1 -type d 2>/dev/null| wc -l)
    [ "$M" == "EQ" ] && [ "$f_count" -eq "$d_count" ] && echo "$dir"
    [ "$M" == "NE" ] && [ "$f_count" -ne "$d_count" ] && echo "$dir"
done
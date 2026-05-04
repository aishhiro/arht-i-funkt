#!/bin/bash

while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "использоватьь: $0 [-e ] [-d каталог]" && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "error key: -$OPTARG" >&2 && exit 1 ;;
    esac
done

dir="${dir:-.}"
[[ -d "$dir" ]] || { echo "errro: $dir не каталог" >&2; exit 1; }

find "$dir" -mindepth 1 -maxdepth 1 -type d -print0 2>/dev/null |
while IFS= read -r -d '' subdir; do
    size=$(du -sb "$subdir" 2>/dev/null | cut -f1)
    [[ -n "$size" ]] && echo "$size $subdir"
done | sort -n -r | while read -r s p; do
    echo "$s байт  $p"
done

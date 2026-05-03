#!/bin/bash

# разбор ключей
while getopts "e:w:h" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        w) min="$OPTARG" ;;
        h) echo "использовать: $0 [-e фаил errorz] -w N кааталог 1 [каталог 2 ...]" && exit 0 ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

# проверки
[[ $# -eq 0 ]] && echo " не указаны каталоги" >&2 && exit 1
[[ -z "$min" || ! "$min" =~ ^[0-9]+$ ]] && echo "укажите число слов через -w" >&2 && exit 1

# поиск файлов с колво слов > min
for dir in "$@"; do
    [[ -d "$dir" ]] || { echo ": $dir не каталог" >&2; continue; }
    find "$dir" -type f | while read -r f; do
        words=$(wc -w < "$f" 2>/dev/null)
        [[ "$words" -gt "$min" ]] && echo "$f"
    done
done

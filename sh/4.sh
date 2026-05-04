#!/bin/bash

while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "используй: $0 [-e файл errorz] [-d каталог] имя" && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

[[ $# -eq 0 ]] && echo "ошибка: не указано имя файла" >&2 && exit 1

filename="$1"

dir="${dir:-.}"

[[ -d "$dir" ]] || { echo "ошибка: $dir не каталог" >&2; exit 1; }

find "$dir" -type f -name "$filename" -printf '%h\n' 2>/dev/null | sort -u

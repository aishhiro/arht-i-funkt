#!/bin/bash
while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "использовать: $0 [-e файл errorz] [-d каталог]" && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done

dir="${dir:-.}"

[[ -d "$dir" ]] || { echo "ошибка: $dir не каталог" >&2; exit 1; }

count=$(find "$dir" -type f 2>/dev/null | wc -l)
echo "файлов в $dir: $count"

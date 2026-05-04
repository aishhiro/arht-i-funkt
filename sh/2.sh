#!/bin/bash

while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "использование: $0 [-e файл errorz] [-d каталог] файлы..." && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done
shift $((OPTIND - 1))  #имена

[[ $# -eq 0 ]] && echo "ошибка: не указаны файлы" >&2 && exit 1

[[ -n "$dir" ]] && cd "$dir" 2>/dev/null || { echo "ошибка: нет каталога $dir" >&2; exit 1; }

total=0
for f in "$@"; do
    [[ -f "$f" ]] || { echo "файл не найден: $f" >&2; continue; }
    n=$(wc -l < "$f")
    echo "$f: $n"
    total=$((total + n))
done

echo "колво строк: $total"

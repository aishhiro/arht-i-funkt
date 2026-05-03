#!/bin/bash

# ключи
while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "использование: $0 [-e файл errorz] [-d каталог] файлы..." && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done
shift $((OPTIND - 1))  # оставление имен файлов

#  нет файлов то ошибка
[[ $# -eq 0 ]] && echo "ошибка: не указаны файлы" >&2 && exit 1

#  задан каталог то в него переход
[[ -n "$dir" ]] && cd "$dir" 2>/dev/null || { echo "ошибка: нет каталога $dir" >&2; exit 1; }

# колво строк
total=0
for f in "$@"; do
    [[ -f "$f" ]] || { echo "файл не найден: $f" >&2; continue; }
    n=$(wc -l < "$f")
    echo "$f: $n"
    total=$((total + n))
done

echo "колво строк: $total"

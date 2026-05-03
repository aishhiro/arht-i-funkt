#!/bin/bash

# разбор ключей
while getopts "e:hd:" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;
        h) echo "используй: $0 [-e файл errorz] [-d каталог] имя" && exit 0 ;;
        d) dir="$OPTARG" ;;
        *) echo "неверный ключ: -$OPTARG" >&2 && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

# проверка что имя файла указано
[[ $# -eq 0 ]] && echo "ошибка: не указано имя файла" >&2 && exit 1

filename="$1"
dir="${dir:-.}"

# проверка существования каталога
[[ -d "$dir" ]] || { echo "ошибка: $dir не каталог" >&2; exit 1; }

# поиск каталога с указ названинем
find "$dir" -type f -name "$filename" -printf '%h\n' 2>/dev/null | sort -u

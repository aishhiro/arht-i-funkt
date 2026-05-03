#!/bin/bash

#аргументы
while getopts "e:h" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;  # перенаправляние stderr 
        h) echo "Используй: $0 [-e файл error]" && exit 0 ;;
        *) echo "Неверный ключ" >&2 && exit 1 ;;
    esac
done

# таблица
printf "%-8s" "N"
for e in {0..6}; do printf "%-12s" "N^$e"; done
echo

# цифры
for n in {1..9}; do
    printf "%-8d" $n
    r=1
    for e in {0..6}; do
        printf "%-12d" $r
        r=$((r * n))
    done
    echo
done

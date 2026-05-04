#!/bin/bash

while getopts "e:h" opt; do
    case $opt in
        e) exec 2>>"$OPTARG" ;;  # перенаправляние stderr 
        h) echo "использовать: $0 [-e файл error]" && exit 0 ;;
        *) echo "неверный ключ" >&2 && exit 1 ;;
    esac
done

printf "%-8s" "N"
for e in {0..6}; do printf "%-12s" "N^$e"; done
echo

for n in {1..9}; do
    printf "%-8d" $n
    r=1
    for e in {0..6}; do
        printf "%-12d" $r
        r=$((r * n))
    done
    echo
done

#!bin/bash

if [ -z "$1" ]; then
    echo "Неправильно введен файл!"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Файл не найден!"
    exit 1
fi

echo $(wc -l < "$1") $(awk '{print $3}' "$1" | sort | uniq | wc -l) $(grep "hash changes" "$1" | wc -l)

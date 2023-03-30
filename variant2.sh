#!/bin/bash

while true; do
    echo "Программа для создания CD-диска"
    echo "При помощью данной программы из указанного каталога можно сделать образ CD-диска в формате .iso"
    echo "Разработчик: Воронков Валентин группа 749-1"

    echo "Текущее содержимое каталога"
    ls -a

    echo "Укажите директорию содержания CD-диска"
    read dir

    echo "Задайте название CD-диска"
    read name_file

    if [ -f "$name_file.iso" ]; then
        name_file="$name_file-$(date +%d-%m-%Y)"
    fi

    genisoimage -o "$name_file.iso" "$dir"
    echo "complete!"
    echo "Обновлённое содержимое каталога"
    ls -a

    echo "Повторить работу?"
    echo "y/n?"
    read ans
    if [ "$ans" != "y" ]; then
        break
    fi
done
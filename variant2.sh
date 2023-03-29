#!/bin/bash

while true; do
    echo "Программа для создания CD-диска"
    echo "При помощью данной программы из указанного каталога можно сделать образ CD-диска в формате .iso"
    echo "Разработчик: Воронков Валентин группа 749-1"


    echo "text"
    read dir

    echo "text2"
    read name_file

    if [ -f "$name_file.iso" ]; then
        name_file="$name_file-$(date +%d-%m-%Y).iso"
    fi

    genisoimage -o "$name_file" "$dir"
    echo "complete!"

    echo "y/n?"
    read ans

    if [ "$ans" != "y" ]; then
        break
    fi
done
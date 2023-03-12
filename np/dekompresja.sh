#!/bin/sh

for i
do
    plik=$(basename -- "$i")
    rozsz="${plik#*.}"
    nazwa="${plik%%.*}"

    if [ $rozsz = "tar.xz" ]
    then

        mkdir -p ${nazwa%.}
        tar -Jxf $plik --directory ${nazwa%.}
    elif [ $rozsz = "zip" ]
    then
        mkdir -p $nazwa
        unzip -qqod $nazwa $nazwa
    elif [ $rozsz = "tar.gz" ]
    then

        mkdir -p $nazwa
        tar -zxf $plik --directory $nazwa
    elif [ $rozsz = "tar.bz2" ]
    then

        mkdir -p $nazwa
        tar -jxf $plik --directory $nazwa
    else
        echo "\n\nPlik $plik nie jest możliwy do dekompresji"
    fi

done
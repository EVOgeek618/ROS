#!/bin/bash
(echo Название,Расширение,Размер,Время создания,Время изменения,Тип,Длительность видео и аудио) >~/files.xls
files()
{
(for i in $1/*
do
if [[ ${i#*.} == $i ]]; then
w="-"
else
w=${i#*.}
fi
r=$(expr length $i)
d=3
e=$(($r+$d))
if [[ $w == "mkv" || $w == "mp4" ]]; then
echo $(stat --printf="%n" $i|rev|cut -f1 -d /|rev),$w,$(stat --printf="%s,%w,%z" $i),$(file $i | cut -c$e-| sed 's/,//g'
),$(mediainfo $i|head -n7|tail -n1|cut -c44-)
elif [[ $w == "mp3" ]]; then
echo $(stat --printf="%n" $i|rev|cut -f1 -d /|rev),$w,$(stat --printf="%s,%w,%z" $i),$(file $i | cut -c$e-| sed 's/,//g'
),$(mediainfo $i|head -n5|tail -n1|cut -c44-)
elif [[ $w == "avi" ]]; then
echo $(stat --printf="%n" $i|rev|cut -f1 -d /|rev),$w,$(stat --printf="%s,%w,%z" $i),$(file $i | cut -c$e-| sed 's/,//g'
),$(mediainfo $i|head -n6|tail -n1|cut -c44-)
elif [[ -d $i ]]; then
files $i
else
echo $(stat --printf="%n" $i|rev|cut -f1 -d /|rev),$w,$(stat --printf="%s,%w,%z" $i),$(file $i | cut -c$e-| sed 's/,//g'
)
fi
done)>>~/files.xls
}
files $1

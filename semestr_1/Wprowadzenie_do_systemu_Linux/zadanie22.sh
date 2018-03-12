#!/bin/bash
function zadanie22
{
	nazwa=$1

	if [ -e $nazwa ]
	then
		echo
		echo "Wybrales plik $nazwa"
	else
		echo
		echo "Taki plik nie istnieje."
	fi


	folder=${nazwa%.*}
	folder=${folder%.*}


	if [ -e $folder ]
	then
	echo "Katalog już istnieje."
	echo
	else
	mkdir $folder
	echo "Stworzono katalog $folder."
	fi

	case $nazwa in
		*.tar)  tar -xf $nazwa -C $folder ;;
		*.gz)  tar -xzf $nazwa -C $folder ;;
		*.zip) unzip -q $nazwa -d $folder ;;
		*) echo "Nie mogę rozpoznać formatu pliku." ;;
	esac
echo "Wypakowano."
echo
}
zadanie22 $1

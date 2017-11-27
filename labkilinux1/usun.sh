#!/bin/bash
echo "Podaj nazwe katalogu ktory chcesz usunac: "
read nazwa
if [ -e $nazwa ]
then
	echo "Czy chcesz usunac katalog $nazwa? [t/n]"
	read czy
	if [ $czy = "t" ] || [ $czy = "T" ] 
	then
		rm -r $nazwa
		echo "Plik usunieto"
	else
		echo "Nie usunieto"	
	fi	
else
	echo "Taki plik nie stnieje"
fi

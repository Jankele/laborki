#!/bin/bash
echo "Podaj nazwe katalogu do usuniecia"; read nazwa
if [ -e $nazwa ]; then
echo "Czy chcesz usunąć $nazwa ?"
read czy
if [ $czy="t" ] || [ $czy="T" ]
then
rm -r $nazwa
echo "Katalog usunięty."
else
echo "Nie usunieto"
fi
else
echo "Katalog nie istnieje"
fi

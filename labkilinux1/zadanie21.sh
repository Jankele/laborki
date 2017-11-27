#!/bin/bash
function wyswietl {
echo "ZADANIE 20:"
echo
echo "Stan pamieci ram: "
echo
free -h
echo
echo
echo "Stan dysku twardego: "
echo
df -ah
echo
echo
echo "ZADANIE 21: "
echo
iostat -c
echo
}
wyswietl

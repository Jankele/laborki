#!/bin/bash
# najlepsze rozwiazanie 
# find /etc -type f -name "*.conf" -exec tar rf ~/backup_'date '+%d-%m-%Y'.tar {} \;
czas=$(date '+%d-%m-%Y')
tar -cf ~/pacz/backup_$czas.tar $( find /etc -maxdepth 1 -name "*.conf" )
echo "Zrobione"


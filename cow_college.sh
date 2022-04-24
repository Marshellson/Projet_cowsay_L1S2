###
 # @Author: JIANG Yilun
 # @Date: 2022-04-24 15:41:00
 # @LastEditTime: 2022-04-24 17:44:13
 # @LastEditors: JIANG Yilun
 # @Description: 
 # @FilePath: /Projet_cowsay_L1S2/cow_college.sh
### 

# nombres de Finonacci

i=0
j=1

if [ $# -eq 0 ]; then
    echo "Saissez un nombre:"
    read nombre
    while [ $j -lt $nombre ]; do
        cowsay $j
        temp=$((i+j))
        i=$j
        j=$temp
        sleep 1
    done
else
    nombre=$1
    while [ $j -lt $nombre ]; do
        cowsay $j
        temp=$((i+j))
        i=$j
        j=$temp
        sleep 1
    done
fi
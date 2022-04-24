###
 # @Author: JIANG Yilun
 # @Date: 2022-04-24 15:41:00
 # @LastEditTime: 2022-04-24 15:53:23
 # @LastEditors: JIANG Yilun
 # @Description: 
 # @FilePath: /Projet_cowsay_L1S2/cow_college.sh
### 

# nombres de Finonacci
echo "Saissez un nombre:"
read nombre
i=0
j=1

while [ $j -lt $nombre ]; do
    cowsay $j
    temp=$((i+j))
    i=$j
    j=$temp
    sleep 1
done
###
 # @Author: JIANG Yilun
 # @Date: 2022-04-24 15:37:56
 # @LastEditTime: 2022-04-24 15:39:12
 # @LastEditors: JIANG Yilun
 # @Description: 
 # @FilePath: /Projet_cowsay_L1S2/cow_highschool.sh
### 

echo "Saissez un nombre:"
read nombre
i=1
while [ $i -le $nombre ]; do
    clear
    cowsay $(($i*$i))
    sleep 1
    i=$((i+1))
done

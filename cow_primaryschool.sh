###
 # @Author: JIANG Yilun
 # @Date: 2022-04-24 15:33:12
 # @LastEditTime: 2022-04-24 15:37:03
 # @LastEditors: JIANG Yilun
 # @Description: 
 # @FilePath: /Projet_cowsay_L1S2/cow_primaryschool.sh
### 

echo "Saissez un nombre:"
read nombre
i=1
while [ $i -le $nombre ]; do
    clear
    cowsay $i
    sleep 1
    i=$((i+1))
done

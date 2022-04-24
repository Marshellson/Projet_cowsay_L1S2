###
 # @Author: JIANG Yilun
 # @Date: 2022-04-24 15:55:25
 # @LastEditTime: 2022-04-24 17:42:31
 # @LastEditors: JIANG Yilun
 # @Description: 
 # @FilePath: /Projet_cowsay_L1S2/cow_university.sh
### 

# echo "donnez le dernier nombres premiers à calculer"
# read n
# i=2     #le premier nombre premier
# a=$(bc <<< "scale=0; sqrt($n)")  #scale=0 n'affiche pas les décimale, scale=1 la première, etc... sqrt() calcule la racine carré. marche grace à la commande bc
# m=3
# echo "voici sa suite de nombres premiers de $i à $n"

nbr_premier() {
    while [ $i -le $m ]
    do
        p=$(($m%$i))
        if [ $p -eq 0 ]
        then
            break
        else
            i=$((i+1))
        fi
        if [ $i -eq $m ]
        then
            if [ $m -eq $n ]
            then
                echo "$m est un nombre premier"
                cowsay -T U "$m"
            else
                echo "$m est un nombre premier"
                cowsay "$m"
            fi
        fi
    done
}

if [ $# -eq 0 ]; then
    echo "donnez le dernier nombres premiers à calculer"
    read n
    i=2     #le premier nombre premier
    a=$(bc <<< "scale=0; sqrt($n)")  #scale=0 n'affiche pas les décimale, scale=1 la première, etc... sqrt() calcule la racine carré. marche grace à la commande bc
    m=3
    echo "voici sa suite de nombres premiers de $i à $n"
    while [ $m -le $n ]
    do
        echo m:$m
        i=2
        nbr_premier $m
        m=$((m+1))
        sleep 1
    done
else
    n=$1
    i=2     #le premier nombre premier
    a=$(bc <<< "scale=0; sqrt($n)")  #scale=0 n'affiche pas les décimale, scale=1 la première, etc... sqrt() calcule la racine carré. marche grace à la commande bc
    m=3
    echo "voici sa suite de nombres premiers de $i à $n"
    while [ $m -le $n ]
    do
        echo m:$m
        i=2
        nbr_premier $m
        m=$((m+1))
        sleep 1
    done
fi
/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-25 15:51:26
 * @LastEditTime: 2022-04-25 16:38:26
 * @LastEditors: JIANG Yilun
 * @Description: 
 * @FilePath: /Projet_cowsay_L1S2/Tamagoshi-vache.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int niveau_de_santé = 5;

void etat(int niveau_de_santé){
    if(niveau_de_santé == 0 || niveau_de_santé == 10){
        printf("byebyelife");
    }
    else if (niveau_de_santé <=3 && niveau_de_santé >= 1 || niveau_de_santé <= 9 && niveau_de_santé >= 7){
        printf("lifesucks");
    }
    else if (niveau_de_santé <= 6 && niveau_de_santé >= 4 || niveau_de_santé )
    {
        printf("liferocks");
    }
}


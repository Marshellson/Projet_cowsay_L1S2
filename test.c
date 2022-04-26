/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-24 20:11:56
 * @LastEditTime: 2022-04-26 17:24:57
 * @LastEditors: JIANG Yilun
 * @Description:
 * @FilePath: /Projet_cowsay_L1S2/test.c
 */

#include <stdio.h>

int problem_nombre_premier(int nombre)
{
    int i;
    for (i = 2; i < nombre; i++)
    {
        if (nombre % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int nombre = 0;
    printf("Entrez un nombre: ");
    scanf("%d", &nombre);
    if (problem_nombre_premier(nombre) == 1)
    {
        printf("%d est un nombre premier\n", nombre);
    }
    else
    {
        printf("%d n'est pas un nombre premier\n", nombre);
    }
    return 0;
}
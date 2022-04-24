/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-24 18:07:27
 * @LastEditTime: 2022-04-24 18:44:29
 * @LastEditors: JIANG Yilun
 * @Description: 
 * @FilePath: /Projet_cowsay_L1S2/newcow.c
 */

#include <stdio.h>
#include <string.h>

int affiche_vache (char *eyes, char *tongue)
{
    if (eyes == NULL && tongue == NULL){
        printf("\n");
        printf("    \\   ^__^\n");
        printf("     \\  (oo)\\_______\n");
        printf("        (__)\\       )\\/\\\n");
        printf("            ||----w |\n");
        printf("            ||     ||\n");
        printf("\n");
        return 0;
    }
    else if (eyes == NULL && tongue != NULL){
        printf("\n");
        printf("    \\   ^__^\n");
        printf("     \\  (oo)\\_______\n");
        printf("        (__)\\       )\\/\\\n");
        printf("         %s ||----w |\n",tongue);
        printf("            ||     ||\n");
        printf("\n");
        return 0;
    }
    else if (eyes != NULL && tongue == NULL){
        printf("\n");
        printf("    \\   ^__^\n");
        printf("     \\  (%s)\\_______\n",eyes);
        printf("        (__)\\       )\\/\\\n");
        printf("            ||----w |\n");
        printf("            ||     ||\n");
        printf("\n");
        return 0;
    }
    else
    {
        printf("\n");
        printf("    \\   ^__^\n");
        printf("     \\  (%s)\\_______\n",eyes);
        printf("        (__)\\       )\\/\\\n");
        printf("         %s ||----w |\n",tongue);
        printf("            ||     ||\n");
        printf("\n");
        return 0;
    }
}

int main (int argc, char *argv[])
{
    char *eyes = NULL;
    char *tongue = NULL;
    char *message = NULL;
    char *tail = NULL;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0)
        {
            eyes = argv[i+1];
        }
        if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--tongue") == 0)
        {
            tongue = argv[i+1];
        }
    }
    printf("%s %s\n", eyes, tongue);
    affiche_vache(eyes, tongue);
}
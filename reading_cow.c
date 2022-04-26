/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-25 13:34:08
 * @LastEditTime: 2022-04-26 17:43:29
 * @LastEditors: JIANG Yilun
 * @Description:
 * @FilePath: /Projet_cowsay_L1S2/reading_cow.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_LENGTH 512

void affiche_vache(int *length, char *message, char *eyes, char *tongue, int *tail)
{
    printf(" -");
    for (int i = 0; i < *length; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("< %s >\n", message);
    printf(" -");
    for (int i = 0; i < *length; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("    \\   ^__^\n");
    printf("     \\  (%s)\\_______\n", eyes);
    printf("        (__)\\       )\\");
    for (int i = 0; i < *tail; i++)
    {
        printf("/\\");
    }
    printf("\n");
    printf("         %s ||----w |\n", tongue);
    printf("            ||     ||\n");
    printf("\n");
}

void update() { printf("\033[H\033[J"); }

void gotoxy(x, y) { printf("\033[%d;%dH", x, y); }

int main(int argc, char *argv[])
{
    FILE *ficher = NULL;
    ficher = fopen(argv[1], "r");
    if (ficher == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    else
    {
        char *eyes = "oo";   // default eyes
        char *tongue = "  "; // default tongue
        char message[MAX_LENGTH] = "";  // default message
        int tail = 1;        // default tail
        int length = 0;
        char c;
        while ((c = fgetc(ficher)) != EOF)
        {
            length++;
            affiche_vache(&length, message, eyes, &c, &tail);
            sleep(1);
            update();
            // char *c_buffer = malloc(strlen(message) + strlen(&c) + 1);
            // strcpy(c_buffer, message);
            // strcat(c_buffer, &c);
            // message = c_buffer;
            message[length - 1] = c;
            message[length] = '\0';
        }
        fclose(ficher);
        length++;
        affiche_vache(&length, message, eyes, tongue, &tail);
    }
}
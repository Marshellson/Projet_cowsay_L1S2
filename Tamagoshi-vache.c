/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-25 15:51:26
 * @LastEditTime: 2022-04-26 17:40:20
 * @LastEditors: JIANG Yilun
 * @Description:
 * @FilePath: /Projet_cowsay_L1S2/Tamagoshi-vache.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LENGTH 512

void update() { printf("\033[H\033[J"); }

void gotoxy(x, y) { printf("\033[%d;%dH", x, y); }

int life = 5;

void etat(int life)
{
    if (life == 0 || life == 10)
    {
        printf("byebyelife");
    }
    else if (life <= 3 && life >= 1 || life <= 9 && life >= 7)
    {
        printf("lifesucks");
    }
    else if (life <= 6 && life >= 4 || life)
    {
        printf("liferocks");
    }
}

void affiche_vache(int *length_vache, char *message_vache, char *eyes_vache, char *tongue_vache, int *tail_vache, int time_tick_vache, int hour, int minite)
{
    update();
    for (int i = 0; i < time_tick_vache; i++)
    {
        update();
        gotoxy(0, 0);
        printf("Time for now: %d:%d\n", hour, minite);
        gotoxy(5, 0);
        time_t t;
        t = time(NULL);
        if (t % 2 == 0)
        {
            printf(" -");
            for (int i = 0; i <= *length_vache; i++)
            {
                printf("-");
            }
            printf("\n");
            printf("< %s >\n", message_vache);
            printf(" -");
            for (int i = 0; i <= *length_vache; i++)
            {
                printf("-");
            }
            printf("\n");
            printf("    \\   ^__^\n");
            printf("     \\  (%s)\\_______\n", eyes_vache);
            printf("        (__)\\       )\\");
            for (int i = 0; i < *tail_vache; i++)
            {
                printf("/\\");
            }
            printf("\n");
            printf("         %s ||----w |\n", tongue_vache);
            printf("            ||     ||\n");
            printf("\n");
        }
        else
        {
            printf(" -");
            for (int i = 0; i <= *length_vache; i++)
            {
                printf("-");
            }
            printf(" \n");
            printf("< %s >\n", message_vache);
            printf(" -");
            for (int i = 0; i <= *length_vache; i++)
            {
                printf("-");
            }
            printf(" \n");
            printf("     \\   ^__^\n");
            printf("      \\  (%s)\\_______\n", "oo");
            printf("         (__)\\       )\\");
            for (int i = 0; i < *tail_vache; i++)
            {
                printf(" /\\");
            }
            printf(" \n");
            printf("          %s ||----w |\n", "  ");
            printf("             ||     ||\n");
            printf(" \n");
        }
        // gotoxy(10, 0);
        sleep(1);
    }
}

void time_count(int time_tick, int hour, int minite, int arr[])
{
    minite += 5;
    if (minite >= 60)
    {
        hour += 1;
        minite -= 60;
    }
    if (hour >= 24)
    {
        hour -= 24;
    }
    arr[0] = hour;
    arr[1] = minite;
}

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
    // Begin the game
    int tail = 1;
    int life = 5;
    int food = 10;
    int time_tick = 5;
    char *eyes = "oo";
    char *tongue = "  ";
    int minite = 0;
    int hour = 0;

    char message[MAX_LENGTH] = "Welcome to the COWSAY Game!";
    int length = strlen(message);
    tongue = "U ";
    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);

    strcpy(message, "Please enter your name: ");
    // *message = "Please enter your name: ";
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, 2, hour, minite);

    char name[20];
    scanf("%s", name);

    strcpy(message, "Hello ");
    strcat(message, name);
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);

    strcpy(message, "Please choose the speed of the game: (1) for slow (default), (2) for medium, (3) for fast");
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, 1, hour, minite);

    int game_speed;
    scanf("%d", &game_speed);

    if (game_speed == 1)
    {
        strcpy(message, "You chose the slow speed, the game will be played in 5 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
        time_tick = 8;
    }
    else if (game_speed == 2)
    {
        strcpy(message, "You chose the medium speed, the tivk will be 3 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
        time_tick = 5;
    }
    else if (game_speed == 3)
    {
        strcpy(message, "You chose the fast speed, the tick will be 1 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
        time_tick = 3;
    }
    else
    {
        strcpy(message, "You chose the wrong thing, so the game will play in default speed, the tick will be 5 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
        time_tick = 5;
    }

    int i = 0;
    time_t seconds_of_start;
    seconds_of_start = time(NULL);
    printf("time: %ld\n", seconds_of_start);

    while (life != 0 || life != 10)
    {
        int arr[2];
        strcpy(message, "What can i do for u? ");
        char str[20];
        sprintf(str, "%ld", seconds_of_start);
        strcat(message, str);
        // printf("%d\n", rand() % 10);
        length = strlen(message);
        time_count(time_tick, hour, minite, arr);
        hour = arr[0];
        minite = arr[1];
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
        i++;
        update();
        if (minite == 0){
            strcpy(message, "It's time to think about something!");
            length = strlen(message);
            affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite);
            int random_number = rand() % 10;
        }
    }
}

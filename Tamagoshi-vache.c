/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-25 15:51:26
 * @LastEditTime: 2022-04-26 22:47:49
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

void affiche_vache(int *length_vache, char *message_vache, char *eyes_vache, char *tongue_vache, int *tail_vache, int time_tick_vache, int hour, int minite, int food)
{
    update();
    for (int i = 0; i < time_tick_vache; i++)
    {
        update();
        gotoxy(0, 0);
        printf("Time for now: %d:%d\tFood: %d\n", hour, minite, food);
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


int check_prime_number(int nombre)
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
    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);

    strcpy(message, "Please enter your name: ");
    // *message = "Please enter your name: ";
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, 2, hour, minite, food);

    char name[20];
    scanf("%s", name);

    strcpy(message, "Hello ");
    strcat(message, name);
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);

    strcpy(message, "Please choose the speed of the game: (1) for slow (default), (2) for medium, (3) for fast");
    length = strlen(message);
    affiche_vache(&length, message, eyes, tongue, &tail, 1, hour, minite, food);

    int game_speed;
    scanf("%d", &game_speed);

    if (game_speed == 1)
    {
        strcpy(message, "You chose the slow speed, the game will be played in 10 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
        time_tick = 8;
    }
    else if (game_speed == 2)
    {
        strcpy(message, "You chose the medium speed, the tivk will be 5 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
        time_tick = 5;
    }
    else if (game_speed == 3)
    {
        strcpy(message, "You chose the fast speed, the tick will be 3 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
        time_tick = 1;
    }
    else
    {
        strcpy(message, "You chose the wrong thing, so the game will play in default speed, the tick will be 5 seconds");
        length = strlen(message);
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
        time_tick = 5;
    }

    int i = 0;
    time_t seconds_of_start;
    seconds_of_start = time(NULL);
    printf("time: %ld\n", seconds_of_start);

    while (life > 0 && life < 10)
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
        tail = life;
        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
        i++;
        update();
        if (minite == 0){
            strcpy(message, "It's time to think about something!");
            length = strlen(message);
            affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
            int random_number = rand() % 5;
            srand(time(NULL));
            // prime number
            if (random_number == 1) {
                int nombre_premier = rand() % 100;
                strcpy(message, "Is it a prime number? (1) for yes, (2) for no: " );
                char str_nombre_premier[MAX_LENGTH] = "";
                sprintf(str_nombre_premier, "%d", nombre_premier);
                strcat(message, str_nombre_premier);

                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                int answer = 0;
                scanf("%d", &answer);
                if (answer == 1) {
                    if (check_prime_number(nombre_premier)) {
                        strcpy(message, "Yes, it is a prime number! You got it! Food + 2");
                        length = strlen(message);
                        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                        food += 2;

                    } else {
                        strcpy(message, "No, it is not a prime number! You lost it!");
                        length = strlen(message);
                        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    }
                } else {
                    if (check_prime_number(nombre_premier)) {
                        strcpy(message, "Yes, it is a prime number! You lost it!");
                        length = strlen(message);
                        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    } else {
                        strcpy(message, "No, it is not a prime number! You got it! Food + 2");
                        length = strlen(message);
                        affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                        food += 2;
                    }
                }
            }
            // addition
            else if (random_number == 2) {
                int nombre_1 = rand() % 100;
                int nombre_2 = rand() % 100;
                strcpy(message, "What is the sum of ");
                char str_nombre_1[MAX_LENGTH] = "";
                char str_nombre_2[MAX_LENGTH] = "";
                sprintf(str_nombre_1, "%d", nombre_1);
                sprintf(str_nombre_2, "%d", nombre_2);
                strcat(message, str_nombre_1);
                strcat(message, " and ");
                strcat(message, str_nombre_2);
                strcat(message, ": ");

                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                int answer = 0;
                scanf("%d", &answer);
                if (answer == nombre_1 + nombre_2) {
                    strcpy(message, "Yes, it is the sum of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You got it! Food + 2");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    food += 2;
                } else {
                    strcpy(message, "No, it is not the sum of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You lost it!");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                }
            }
            // multiplication
            else if (random_number == 3) {
                int nombre_1 = rand() % 100;
                int nombre_2 = rand() % 10;
                strcpy(message, "What is the product of ");
                char str_nombre_1[MAX_LENGTH] = "";
                char str_nombre_2[MAX_LENGTH] = "";
                sprintf(str_nombre_1, "%d", nombre_1);
                sprintf(str_nombre_2, "%d", nombre_2);
                strcat(message, str_nombre_1);
                strcat(message, " and ");
                strcat(message, str_nombre_2);
                strcat(message, ": ");

                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                int answer = 0;
                scanf("%d", &answer);
                if (answer == nombre_1 * nombre_2) {
                    strcpy(message, "Yes, it is the product of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You got it! Food + 2");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    food += 2;
                } else {
                    strcpy(message, "No, it is not the product of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You lost it!");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                }
            }
            // difference
            else if (random_number == 4) {
                int nombre_1 = rand() % 100;
                int nombre_2 = rand() % 100;
                strcpy(message, "What is the difference of ");
                char str_nombre_1[MAX_LENGTH] = "";
                char str_nombre_2[MAX_LENGTH] = "";
                sprintf(str_nombre_1, "%d", nombre_1);
                sprintf(str_nombre_2, "%d", nombre_2);
                strcat(message, str_nombre_1);
                strcat(message, " and ");
                strcat(message, str_nombre_2);
                strcat(message, ": ");

                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                int answer = 0;
                scanf("%d", &answer);
                if (answer == nombre_1 - nombre_2) {
                    strcpy(message, "Yes, it is the difference of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You got it! Food + 2");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    food += 2;
                } else {
                    strcpy(message, "No, it is not the difference of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You lost it!");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                }
            }
            // mod
            else if (random_number == 5) {
                int nombre_1 = rand() % 100;
                int nombre_2 = rand() % 10;
                strcpy(message, "What is the mod of ");
                char str_nombre_1[MAX_LENGTH] = "";
                char str_nombre_2[MAX_LENGTH] = "";
                sprintf(str_nombre_1, "%d", nombre_1);
                sprintf(str_nombre_2, "%d", nombre_2);
                strcat(message, str_nombre_1);
                strcat(message, " and ");
                strcat(message, str_nombre_2);
                strcat(message, ": ");

                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                int answer = 0;
                scanf("%d", &answer);
                if (answer == nombre_1 % nombre_2) {
                    strcpy(message, "Yes, it is the mod of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You got it! Food + 2");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                    food += 2;
                } else {
                    strcpy(message, "No, it is not the mod of ");
                    strcat(message, str_nombre_1);
                    strcat(message, " and ");
                    strcat(message, str_nombre_2);
                    strcat(message, "! You lost it!");
                    length = strlen(message);
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                }
            }
        }
        if (hour % 6 == 0 && minite == 0) {
            strcpy(message, "It's time to eat! Do you want to eat? (1 for yes, food - 5, life + 2; 0 for no, life - random number)");
            length = strlen(message);
            affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
            int answer = 0;
            scanf("%d", &answer);
            if (answer == 1) {
                if (food > 0) {
                    food -= 5;
                    strcpy(message, "You ate! Food - 5");
                    length = strlen(message);
                    life += 2;
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                } else {
                    strcpy(message, "You don't have enough food!");
                    length = strlen(message);
                    int random_number = rand() % (life - 1);
                    life -= random_number;
                    affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
                }
            } else {
                int random_number = rand() % (life - 1);
                life -= random_number;
                strcpy(message, "You didn't eat! Life - ");
                char str_random_number[MAX_LENGTH] = "";
                sprintf(str_random_number, "%d", random_number);
                strcat(message, str_random_number);
                length = strlen(message);
                affiche_vache(&length, message, eyes, tongue, &tail, time_tick, hour, minite, food);
            }
        }
    }
}

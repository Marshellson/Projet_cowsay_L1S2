/*
 * @Author: JIANG Yilun
 * @Date: 2022-04-24 18:07:27
 * @LastEditTime: 2022-04-24 19:01:13
 * @LastEditors: JIANG Yilun
 * @Description: 
 * @FilePath: /Projet_cowsay_L1S2/newcow.c
 */

#include <stdio.h>
#include <string.h>

int affiche_vache (int *length, char *message, char *eyes, char *tongue)
{
    printf(" -");
    for (int i = 0; i < *length; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("<%s>\n", message);
    printf(" -");
    for (int i = 0; i < *length; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("    \\   ^__^\n");
    printf("     \\  (%s)\\_______\n",eyes);
    printf("        (__)\\       )\\/\\\n");
    printf("         %s ||----w |\n",tongue);
    printf("            ||     ||\n");
    printf("\n");
    return 0;
}

int main (int argc, char *argv[])
{
    char *eyes = "oo";
    char *tongue = "  ";
    char *message = "";
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
        if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--message") == 0)
        {
            message = argv[i+1];
        }
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            printf("\n");
            printf("Usage: newcow [OPTION]...\n");
            printf("\n");
            printf("Options:\n");
            printf("  -e, --eyes=STRING  eyes of the cow (default: oo)\n");
            printf("  -t, --tongue=STRING tongue of the cow (default:  )\n");
            printf("  -m, --message=STRING message to display (default: none)\n");
            printf("  -h, --help          display this help and exit\n");
            printf("\n");
            return 0;
        }
    }
    printf("%s %s\n", eyes, tongue);
    int length = strlen(message) - 1;
    affiche_vache(&length, message, eyes, tongue);
}
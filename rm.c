#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // printf("%s\n", "yes");
    char array[1000][1000];
    char *tok = strtok(argv[1], " ");
    int i = 0;
    int size = 1;
    while (tok != NULL)
    {
        strcpy(array[i], tok);
        // printf("%s\n", array[i]);
        tok = strtok(NULL, " ");
        i++;
    }
    size = i;
    i = 0;
    if (size == 2)
    {
        if (unlink(array[1]) == 0)
        {
            ;
        }
        else
        {
            printf("Error: can't remove the following file/directory");
        }
    }
    else if (size == 3)
    {
        if (strcmp(array[1], "-d") == 0)
        {
            if (rmdir(array[2]) == 0)
                printf("%s", "removed");
            else
            {
                printf("Error: can't remove the following file/directory");
            }
        }
        else if (strcmp(array[1], "-v") == 0)
        {
            if (unlink(array[2]) == 0)
            {
                printf("%s", "removed");
            }
            else
            {
                printf("Error: can't remove the following file/directory");
            }
        }
        else
        {
            printf("Error : Invalid command");
        }
    }
    else
    {
        printf("Error: Invalid command.. ");
    }
}
/*int main(int argc, char argv[1000][1000])
{
    char *tok = strtok(argv[1], " ");
    if (strcmp(tok[0], '-') == 0)
    {
        tok = strtok(NULL, " ");
    }
    while (tok != NULL)
    {
        if (strcmp(tok[1], 'd') == 0)
        {
            if (rmdir(tok) == 0)
                printf("%s", "removed");
            tok = strtok(NULL, " ");
        }
        else if (strcmp(tok[1], 'v') == 0)
        {
            if (unlink(tok) == 0)
            {
                printf("%s", "removed");
            }
            tok = strtok(NULL, " ");
        }
        else if (strcmp(tok[1], '\0') == 0)
        {
            if (unlink(tok) == 0)
            {
                printf("%s", "removed");
            }
            tok = strtok(NULL, " ");
        }
        else
        {
            printf("%s", "Invalid Input");
            return 0;
        }
    }
}*/
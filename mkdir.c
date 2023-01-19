#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int modeDirectoryMaker(char file[1000], int mode)
{
    if (mkdir(file, mode) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

    if (size == 1)
    {
        printf("Error: Incomplete command");
    }
    // char *toker = strtok(array[1], NULL);
    //  printf("%s", array[1]);
    else if (size == 2)
    {
        if (mkdir(array[1], 0777) == 0)
        {
            ;
        }
        else
        {
            printf("Error: Can't create a directory here");
        }
    }
    else if (strcmp(array[1], "-v") == 0)
    {
        // printf("%s\n", "yes");
        if (mkdir(array[2], 0777) == 0)
        {
            printf("directory created \n");
        }
        else
        {
            printf("Error: Can't create a directory here");
        }
    }
    else if (strcmp(array[1], "-m") == 0)
    {
        if (strcmp(array[2], "a=rwx"))
        {
            int x = modeDirectoryMaker(array[3], 0777);
            if (x == 0)
            {
                printf("Error: Can.t create a directory of given permission here");
            }
            // 777
        }
        else if (strcmp(array[2], "a=r") == 0)
        {
            int x = modeDirectoryMaker(array[3], 0400);
            if (x == 0)
            {
                printf("Error: Can.t create a directory of given permission here");
            }
            // 400
        }
        else if (strcmp(array[2], "a=rw") == 0)
        {
            int x = modeDirectoryMaker(array[3], 0110);
            if (x == 0)
            {
                printf("Error: Can.t create a directory of given permission here");
            }
            // 110
        }
        else if (strcmp(array[2], "a=w"))
        {
            int x = modeDirectoryMaker(array[3], 0200);
            if (x == 0)
            {
                printf("Error: Can.t create a directory of given permission here");
            }
            // 200
        }
    }
    else
    {
        printf("Invalid command.. ");
    }

    /*else
    {
        if (mkdir(array[2], 777) == 0)
        {
            ;
        }
    }*/

    /*for (int i = 0; i < size; i++)
{
    printf("%s", array[i]);
}*/

    /*char *tok = strtok(argv[1], " ");
    char Command[1024] = tok;
    tok = strtok(NULL, " ");
    if (strcmp(tok[0], '-') == 0)
    {
        tok = strtok(NULL, " ");
    }*/
    // printf("%s \n", "YES");
    //  printf("%s", argv[1]);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
struct dirent **namelist;
int directoryScanner()
{

    int n = scandir(".", &namelist, NULL, alphasort);
    return n;
}
int main(int argc, char *argv[])
{
    printf("yes");
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
    // printf("%d\n", size);
    // struct dirent **namelist;
    if (size == 1)
    {
        // printf("%d\n", 1);
        int n = directoryScanner();
        // printf("%d\n", n);
        int i = 0;
        for (i = 0; i < n; i++)
        {
            printf("%s ", namelist[i]->d_name);
            free(namelist[i]);
        }
        printf("\n");
        free(namelist);
    }
    else
    {
        if (size == 2)
        {
            if (strcmp(array[1], "-a") == 0)
            {
                int n = directoryScanner();
                int i = 0;
                for (i = 0; i < n; i++)
                {
                    printf("%s ", namelist[i]->d_name);
                    free(namelist[i]);
                }
                printf("\n");
                free(namelist);
            }
            else if (strcmp(array[1], "-r") == 0)
            {
                int n = directoryScanner();
                int i = 0;
                for (i = 0; i < n; i++)
                {
                    printf("%s ", namelist[n - 1 - i]->d_name);
                    free(namelist[n - 1 - i]);
                }
                printf("\n");
                free(namelist);
            }
        }
        else
        {
            int n = scandir(array[2], &namelist, NULL, alphasort);
            int i = 0;
            for (i = 0; i < n; i++)
            {
                printf("%s ", namelist[i]->d_name);
                free(namelist[i]);
            }
            printf("\n");
            free(namelist);
        }
    }
}
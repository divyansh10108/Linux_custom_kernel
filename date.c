#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>

time_t r;

int main(int argc, char *argv[])
{
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

        if (r != -1)
        {
            r = time(NULL);
            struct tm *ptm;
            ptm = localtime(&r);
            char buf1[4];
            char buf2[4];
            char buf3[6];
            strftime(buf1, 4, "%a", ptm);
            strftime(buf2, 4, "%b", ptm);
            strftime(buf3, 6, "%z", ptm);
            strcat(buf1, " ");
            strcat(buf1, buf2);
            strcat(buf1, " ");
            int hello = ptm->tm_year + 1900;
            printf("%s%02d %02d:%02d:%02d %s %d\n", buf1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, buf3, hello);
        }
        else
        {
            printf("Invlid command...");
        }
    }
    else
    {
        if (strcmp(array[1], "-u") == 0)
        {
            r = time(NULL);
            struct tm *ptm;
            ptm = localtime(&r);
            char buf1[4];
            char buf2[4];
            char buf3[6];
            strftime(buf1, 4, "%a", ptm);
            strftime(buf2, 4, "%b", ptm);
            strftime(buf3, 6, "%z", ptm);
            strcat(buf1, " ");
            strcat(buf1, buf2);
            strcat(buf1, " ");
            int hello = ptm->tm_year + 1900;
            printf("%s%02d %02d:%02d:%02d %sUTC %d\n", buf1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, buf3, hello);
        }
        else if (strcmp(array[1], "-R") == 0)
        {
            r = time(NULL);
            struct tm *ptm;
            ptm = localtime(&r);
            char buf1[4];
            char buf2[4];
            char buf3[6];
            strftime(buf1, 4, "%a", ptm);
            strftime(buf2, 4, "%b", ptm);
            strftime(buf3, 6, "%z", ptm);
            int hello = ptm->tm_year + 1900;
            printf("%s, %02d %s %d %02d:%02d:%02d %s\n", buf1, ptm->tm_mday, buf2, hello, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, buf3);
        }
        else
        {
            printf("Invlid command...");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

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
    if (size == 2)
    {
        int f = open(array[1], O_RDONLY);
        if (f >= 0)
        {
            char ch[1];
            int sz;
            while ((sz = read(f, &ch, 1)))
            {
                if (write(STDIN_FILENO, &ch, 1) >= 0)
                {
                    ;
                }
                else
                {
                    printf("Error: Cannot complete the writting process ");
                }
            }
            int clo = close(f);

            if (clo < 0)
            {
                printf("Closing Error");
            }
        }

        else
        {
            printf("Wrong file name");
        }
    }
    else if (size == 3)
    {
        if (strcmp(array[1], "-E") == 0)
        {
            int f = open(array[2], O_RDONLY);
            if (f >= 0)
            {
                char ch[2];
                int sz;
                while ((sz = read(f, &ch, 1)))

                {
                    if (strcmp(ch, "\n") == 0)
                    {
                        char p = '$';
                        if (write(STDIN_FILENO, &p, 1) >= 0)
                        {
                            ;
                        }
                        else
                        {
                            printf("Error: Cannot complete the writting process ");
                        }
                    }
                    if (write(STDIN_FILENO, &ch, 1) >= 0)
                    {
                        ;
                    }
                    else
                    {
                        printf("Error: Cannot complete the writting process ");
                    }
                }
                int clo = close(f);
                if (clo < 0)
                {
                    printf("Closing Error");
                }
            }
        }
        else if (strcmp(array[1], "-n") == 0)
        {
            int f = open(array[2], O_RDONLY);
            if (f >= 0)
            {
                char ch[2];
                int sz;
                char a = '1';
                char sp[2] = " ";
                write(STDIN_FILENO, &a, 1);
                write(STDIN_FILENO, &sp, 1);
                a = '2';
                while ((sz = read(f, &ch, 1)))

                {
                    if (strcmp(ch, "\n") == 0)
                    {
                        if (write(STDIN_FILENO, &ch, 1) >= 0)
                        {
                            write(STDIN_FILENO, &a, 1);
                            write(STDIN_FILENO, &sp, 1);
                            a += 1;
                        }
                        else
                        {
                            printf("Error: Cannot complete the writting process ");
                        }
                    }
                    else if (write(STDIN_FILENO, &ch, 1) >= 0)
                    {
                        ;
                    }
                    /*if (strcmp(ch, "9") == 0)
                    {
                        char p = '^';
                        if (write(STDIN_FILENO, &p, 1) >= 0)
                        {
                            ;
                        }
                        else
                        {
                            printf("Error: Cannot complete the writting process ");
                        }

                        p = 'I';
                        if (write(STDIN_FILENO, &p, 1) >= 0)
                        {
                            ;
                        }
                        else
                        {
                            printf("Error: Cannot complete the writting process ");
                        }
                    }
                    else if (write(STDIN_FILENO, &ch, 1) >= 0)
                    {
                        ;
                    }*/
                }
                int clo = close(f);
                if (clo < 0)
                {
                    printf("Closing Error");
                }
            }
        }
        else
        {
            printf("Invalid command");
        }
    }
    else
    {
        printf("Invalid command");
    }
}

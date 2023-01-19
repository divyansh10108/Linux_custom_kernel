#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>

void callFuncMkdir(int f, char commandCopy[], char *temp)
{
    pid_t id;
    int stat;
    if (f == 1)
    {
        if ((id = fork()) == 0)
        {

            // char a[1024] = getcwd(arr, sizeof(arr));

            char *args[] = {temp, commandCopy, NULL};
            execl(temp, temp, commandCopy, NULL);
            exit(0);
        }
        else
        {
            // printf("%s", "no");
            pid_t time = wait(&stat);
        }
    }
}

void callFuncCat(int f, char commandCopy[], char *temp)
{
    pid_t id;
    int stat;
    if (f == 1)
    {
        if ((id = fork()) == 0)
        {
            // printf("%s\n", "yes");
            char arr[1024];
            char *temp = getcwd(arr, sizeof(arr));
            strcat(temp, "/cat");

            // char a[1024] = getcwd(arr, sizeof(arr));

            char *args[] = {temp, commandCopy, NULL};
            execl(temp, temp, commandCopy, NULL);
            exit(0);
        }
        else
        {
            // printf("%s", "no");
            pid_t time = wait(&stat);
        }
    }
}
void callFuncRm(int f, char commandCopy[], char *temp)
{
    pid_t id;
    int stat;
    if (f == 1)
    {
        if ((id = fork()) == 0)
        {
            // printf("%s\n", "yes");
            char *args[] = {temp, commandCopy, NULL};
            execl(temp, temp, commandCopy, NULL);
            exit(0);
        }
        else

        {
            // printf("%s", "no");
            pid_t time = wait(&stat);
        }
    }
}
void callFuncDate(int f, char commandCopy[], char *temp)
{
    pid_t id;
    int stat;
    if (f == 1)
    {
        if ((id = fork()) == 0)
        {
            // printf("%s\n", "yes");
            char *args[] = {temp, commandCopy, NULL};
            execl(temp, temp, commandCopy, NULL);
            exit(0);
        }
        else
        {
            // printf("%s", "no");
            pid_t time = wait(&stat);
        }
    }
}

void cdChanger()
{
    char temp[200];
    printf("%s", getcwd(temp, sizeof(temp)));
}
void cdChangerSpecial(char array[1000][1000])
{
    char buf[PATH_MAX];
    char *res = realpath(strtok(array[2], "\n"), buf);
    if (res)
    {
        printf("%s\n", res);
        cdChanger();
    }
    else
    {
        printf("Error: invalid input...");
    }
}

void pwdLocater()
{
    char newarr[1024];
    char *cwd = getcwd(newarr, sizeof(newarr));
    printf("%s", cwd);
}

void runPwd(char array[1000][1000], int flag, int size)
{

    if (strcmp(array[1], "-P") == 0)
    {
        pwdLocater();
    }
    else if (strcmp(array[1], "-L") == 0)
    {
        char buf[PATH_MAX];
        char a[1024];
        // char *result = realpath(a, buf);
        char *temp = getcwd(a, sizeof(a));
        printf("%s", realpath(a, buf));
    }
    else if (size == 1)
    {
        char arr[1024];
        char *temp = getcwd(arr, sizeof(arr));
        printf("%s", temp);
    }
    else
    {
        printf("Invalid command... ");
    }
}

void runEcho(char array[1000][1000], int flag, int size)
{
    if (strcmp(array[1], "-n") == 0 || strcmp(array[1], "-e") == 0)
    {
        for (int i = 0; i < size - 2; i++)
        {
            int j = 0;
            while (array[i + 2][j] != '\0')
            {

                if (array[i + 2][j] == '\\')
                {
                    if (array[i + 2][j + 1] == 'n')
                    {
                        ;
                    }
                    j += 2;
                }
                else
                {
                    printf("%c", array[i + 2][j]);
                }
                j++;
            }
            // printf("%s ", array[i + 2]);
        }
    }
    else
    {

        for (int i = 1; i < size; i++)
        {
            /* code */
            printf("%s ", array[i]);
        }
    }
}
char *yyyy;
char commandMain[1024];
void *callLs(void *arg)
{

    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));
    char hell[1024];
    strcpy(hell, temp);
    strcat(hell, "/ls ");
    strcat(hell, "\"");
    strcat(hell, commandMain);
    strcat(hell, "\"");

    system(hell);
    // char *args[] = {yyyy, commandCopy, NULL};
    // strcat(yyyy, " ");

    // strcat(yyyy, NULL);
    //  system(yyyy);
    /*
    char *args[] = {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};
    execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);*/
    // exit(0);
    pthread_cancel(pthread_self());
    return NULL;
}
void *callMkdir(void *arg)
{

    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));
    char hell[1024];
    strcpy(hell, temp);
    strcat(hell, "/mkdir ");

    strcat(hell, "\"");
    strcat(hell, commandMain);
    strcat(hell, "\"");

    system(hell);

    // char *args[] = {yyyy, commandCopy, NULL};
    // strcat(yyyy, " ");

    // strcat(yyyy, NULL);
    //  system(yyyy);
    /*
    char *args[] = {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};
    execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);*/
    // exit(0);
    pthread_cancel(pthread_self());
    return NULL;
}
void *callCat(void *arg)
{

    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));
    char hell[1024];
    strcpy(hell, temp);
    strcat(hell, "/cat ");
    strcat(hell, "\"");
    strcat(hell, commandMain);
    strcat(hell, "\"");

    system(hell);

    // char *args[] = {yyyy, commandCopy, NULL};
    // strcat(yyyy, " ");

    // strcat(yyyy, NULL);
    //  system(yyyy);
    /*
    char *args[] = {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};
    execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);*/
    // exit(0);
    pthread_cancel(pthread_self());
    return NULL;
}
void *callRm(void *arg)
{

    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));
    char hell[1024];
    strcpy(hell, temp);
    strcat(hell, "/rm ");
    strcat(hell, "\"");
    strcat(hell, commandMain);
    strcat(hell, "\"");

    system(hell);

    // char *args[] = {yyyy, commandCopy, NULL};
    // strcat(yyyy, " ");

    // strcat(yyyy, NULL);
    //  system(yyyy);
    /*
    char *args[] = {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};
    execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);*/
    // exit(0);
    pthread_cancel(pthread_self());
    return NULL;
}
void *callDate(void *arg)
{

    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));
    char hell[1024];
    strcpy(hell, temp);
    strcat(hell, "/date ");
    strcat(hell, "\"");
    strcat(hell, commandMain);
    strcat(hell, "\"");

    system(hell);

    // char *args[] = {yyyy, commandCopy, NULL};
    // strcat(yyyy, " ");

    // strcat(yyyy, NULL);
    //  system(yyyy);
    /*
    char *args[] = {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};
    execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);*/
    // exit(0);
    pthread_cancel(pthread_self());
    return NULL;
}

void runCd(char array[1000][1000], int flag)
{
    if (flag == 0)
    {
        if (chdir(getenv("HOME")) == 0)
        {
            cdChanger();
        }
        else
        {
            printf("Home environment not available...");
        }
    }
    else
    {

        if (strcmp(array[1], "..") == 0)
        {
            int condi = chdir("..");
            if (condi == 0)
            {

                cdChanger();
            }
            else
            {
                printf("No possible higher directory...");
            }
        }
        else if (strcmp(array[1], "~") == 0)
        {
            if (chdir(getenv("HOME")) == 0)
            {
                cdChanger();
            }
            else
            {
                printf("Wrong requested environment..");
            }
        }
        else if (strcmp(array[1], "--") == 0)
        {
            if (chdir(getenv("HOME")) == 0)
            {
                cdChanger();
            }
            else
            {
                printf("Wrong requested environment..");
            }
        }

        else if (strcmp(array[1], "-p") == 0)
        {
            if (array[2] == NULL)
            {
                if (chdir(getenv("HOME")) == 0)
                {
                    cdChangerSpecial(array);
                }
                else
                {
                    printf("Home environment not available...");
                }
            }
            else
            {
                char buf[PATH_MAX];
                char *path = strtok(array[2], "\n");
                char *result = realpath(path, buf);
                if (result)
                {
                    if (chdir(result) == 0)
                    {
                        cdChanger();
                    }
                    else
                    {
                        printf("Unable to move to the asked directory");
                    }
                }
                else
                {
                    printf("Directory not found...");
                }
            }
        }
        else if (strcmp(array[1], "-l") == 0)
        {
            if (array[2] == NULL)
            {
                if (chdir(getenv("HOME")) == 0)
                {
                    cdChanger();
                }
                else
                {
                    printf("Home environment not available...");
                }
            }
            else
            {
                int temp = chdir(strtok(array[2], "\n"));
                if (temp == 0)
                {
                    cdChanger();
                }
                else
                {
                    printf("Unable to move to the asked directory");
                }
            }
        }
        else
        {
            if (chdir(strtok(array[2], "\n")) == 0)
            {
                cdChanger();
            }
            else
            {
                printf("Unable to move to the asked directory");
            }
        }
    }
}

int main()
{
    printf("-------------------shell-----------------");
    int condi = 1;
    char commands[10][10] = {"cd", "echo", "history", "pwd", "exit", "ls", "cat", "date", "rm", "mkdir"};
    char arr[1024];
    char *temp = getcwd(arr, sizeof(arr));

    while (condi == 1)
    {

        // symbol for command run
        printf("\n");
        printf("$ ");
        char command[1000];
        char commandCopy[1000];

        char array[1000][1000];
        int hello = 0;
        scanf("%[^\n]%*c", command);

        // char a[1024] = getcwd(arr, sizeof(arr));
        strcpy(commandMain, command);
        strcpy(commandCopy, command);
        // printf("%s", commandCopy);
        char *tok = strtok(command, " ");
        int i = 0;
        int size = 1;
        ;
        while (tok != NULL)
        {
            strcpy(array[i], tok);
            // printf("%s\n", array[i]);
            tok = strtok(NULL, " ");
            i++;
        }
        size = i;
        i = 0;
        if (strcmp(array[size - 1], "&t") == 0)
        {
            strtok(commandMain, "&");
        }
        /*for (int i = 0; i < 9; i++)
        {
            if (commands[i] == array[0])
            {
                hello = 1;
            }
                }
        if (hello == 0)
        {
            printf("Wrong command");
        }
        else
        {*/
        // check for an error here
        if (strcmp(array[0], "cd") == 0)
        {
            int flag = 1;
            if (size == 1)
                flag = 0;
            runCd(array, flag);
        }
        else if (strcmp(array[0], "echo") == 0)
        {

            int flag = 1;
            if (size == 1)
                flag = 0;
            runEcho(array, flag, size);
        }
        else if (strcmp(array[0], "pwd") == 0)
        {
            int flag = 1;
            if (size == 1)
                flag = 0;
            runPwd(array, flag, size);
        }
        else if (strcmp(array[0], "ls") == 0)
        {
            if (strcmp(array[size - 1], "&t") == 0)
            {
                pthread_t th;
                pthread_create(&th, NULL, callLs, NULL);
                pthread_join(th, NULL);
            }
            else
            {
                pid_t id;
                int stat;
                char hell[1024];
                strcpy(hell, temp);
                strcat(hell, "/ls");
                if ((id = fork()) == 0)
                {
                    // printf("%s\n", "yes");
                    char *args[] = {hell, commandCopy, NULL};
                    // execvp(hell, args);
                    execl(hell, hell, commandCopy, NULL);
                    exit(0);
                }
                else
                {
                    // printf("%s", "no");
                    pid_t time = wait(&stat);
                }
            }
            // strcpy(yyyy, temp);
            //  strcat(yyyy, "/ls");

            /* if ()
            // i
            f
             ((id = fork()) == 0)
            {










                // printf("%s\n", "yes");

                char *args[] =
                 {"/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", commandCopy, NULL};

                execvp("/home/slimeybutter/a1/demomain/a1/hello/Assignment/ls", args);
                e
                x
                i
                t
                (0);
            }
            else
            {
                // printf("%s", "no");
                pid_t time;
                time = wait(&stat);
            }*/
        }
        else if (strcmp(array[0], "cat") == 0)
        {
            if (strcmp(array[size - 1], "&t") == 0)
            {
                pthread_t th;
                pthread_create(&th, NULL, callCat, NULL);
                pthread_join(th, NULL);
            }
            else
            {
                char hell[1024];
                strcpy(hell, temp);

                strcat(hell, "/cat");

                callFuncCat(1, commandCopy, hell);
            }
        }
        else if (strcmp(array[0], "mkdir") == 0)
        {
            if (strcmp(array[size - 1], "&t") == 0)
            {

                pthread_t th;
                pthread_create(&th, NULL, callMkdir, NULL);
                pthread_join(th, NULL);
            }
            else
            {

                char hell[1024];
                strcpy(hell, temp);
                // printf("%s", hell);
                strcat(hell, "/mkdir");

                callFuncMkdir(1, commandCopy, hell);
            }
        }
        else if (strcmp(array[0], "date") == 0)
        {
            if (strcmp(array[size - 1], "&t") == 0)
            {
                pthread_t th;

                pthread_create(&th, NULL, callDate, NULL);
                pthread_join(th, NULL);
            }
            else
            {
                char hell[1024];
                strcpy(hell, temp);
                strcat(hell, "/date");

                callFuncDate(1, commandCopy, hell);
            }
        }
        else if (strcmp(array[0], "rm") == 0)
        {
            if (strcmp(array[size - 1], "&t") == 0)
            {
                pthread_t th;

                pthread_create(&th, NULL, callRm, NULL);
                pthread_join(th, NULL);
            }
            else
            {
                char hell[1024];
                strcpy(hell, temp);
                strcat(hell, "/rm");

                callFuncRm(1, commandCopy, hell);
            }
        }
        else
        {
            printf("Invalid command....");
        }
    }
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80




int fork_cmd(char** args, bool and)
{
    pid_t pid;
    pid = fork();
    switch (pid)
    {
        case -1:
            /* Failure */
            perror("Fork Failed");
            return -1;
        case 0:
            /* child */
            //with argv? or with IO
            if (execvp(args[0], args)==-1)
            {
                printf("%s: command not found\n", args[0]);
                return -1;
            }
        default:
            if (!and)
            {
                wait(NULL);
                return 0;
            }

    }
    return 69;
}

int main(void)
{
    char *args[MAX_LINE/2+1];
    int argc = 0;
    int should_run = 1;
    char* arg_string = malloc(MAX_LINE);
    bool and = false;

    printf("application starting, ...\n");


    while(should_run)
    {
        printf("osh>");
        fflush(stdout);
        fgets(arg_string, MAX_LINE/2+1, stdin);

        //printf("trying to replace last char\n");
        //arg_string[strlen(arg_string)-1] = 0;
        if(arg_string[strlen(arg_string)-1] == '\n')
        {
            arg_string[strlen(arg_string)-1] = 0;
        }

        //printf("checking if '&' exists\n");
        for (size_t i = 0; i < MAX_LINE/2+1; ++i)
        {
            if ((and = (arg_string[i]=='&')))
                break;
        }

        char* token = strtok(arg_string, " ");

        while(token)
        {
            if(*token!='&')
            {
                //printf("adding %s to array args\n", token);
                args[argc]=token;
            }
            token = strtok(NULL," ");
            argc++;
        }
        //0 is equal as the difference between the strings (in binary) is 0
        if (strcmp(args[0], "exit")==0)
        {
            printf("exiting...\n");
            should_run = 0;
            break;
        }


        fork_cmd(args, and);
        for (size_t i = 0; i < argc; i++)
        {
            strcpy(args[i], "\0");
        }
    }


    free(arg_string);
    return should_run;
}

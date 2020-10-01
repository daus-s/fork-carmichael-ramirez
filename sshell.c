#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE = 80

int count_tokens(const char* str)
{

}


char** split(const char* str)
{
    char** args;//asfkjbaskjfbaskj askjnfkasjnfkasjnfajnfkasjnfkjsa
    int argc = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i]==' ')
        {
            if (i!=start_previous)
            {
                if (strlen(token)!=0)
                {
                    argc++;
                }
            }
        }
    }
    //defintely wrong
    args* = new char*[argc];
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i]==' ')
        {
            if (i!=start_previous)
            {
                if (strlen(token)!=0)
                {
                    argc++;
                }
            }
        }
        else
        {
            //apend str[i] (char) to token if not space
            char* token = strcat(token, (char[2]) { (char) str[i], '\0' } );
        }
    }
}

int main(void)
{
    char *args[MAX_LINE/2+1];
    int should_run = 1;
    const char* arg_string;

    printf("Alarm application starting, ...\n");


    while(should_run)
    {
        printf("osh>");
        fflush(stdout);
        gets(arg_string);

        pid_t pid;
        pid = fork();
        switch (pid)
        {
            case -1:
                /* Failure */
                perror("Fork Failed");
                return -1;
            default:
                /* child */
                wait(NULL);
                //with argv? or with IO
                execvp();
                return 0;
        }
    }
}

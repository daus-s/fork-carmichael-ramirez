#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE = 80

char** split(const char* str)
{
    
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

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE = 80



int main(void)
{
    char *args[MAX_LINE/2+1];
    int should_run = 1;

    while(should_run)
    {
        printf("osh>");
        fflush(stdout);
    }

    printf("Alarm application starting, ...\n");

    pid = fork();
    switch (pid) {
        case -1:
            /* Failure */
            perror("Fork Failed");
            return -1;
        case 0:
            /* child */
           wait(NULL);
           //with argv? or with IO
           execvp();
           return 0;
   }

}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



char** split(const char* str)
{
    printf("entering split, for string: %s\n", str);
    int argc = 0;
    //assign maximum size to both each token and total arg length
    char* token = malloc(80);
    char args[80][80];
    for (int i = 0; i < strlen(str); ++i)
    {
        //printf(str[i]==' ' ? "true\n" : "false\n");
        if (str[i]==' ')
        {
            //printf(strlen(token)!=0 ? "true\n" : "false\n");
            if (strlen(token)!=0)
            {

                strcpy(args[argc], token);
                argc++;
                for (int j = 0; j < argc; j++)
                {
                      printf("%s,%d/%d\n", args[j],j+1, argc);
                }
                //printf("before reset:%s\n", token);
                strcpy(token, "");
                //printf("after reset:%s\n", token);


            }
        }
        else //not equal to space char
        {
            //printf("adding char to token\n");
            token = strcat(token, (char[2]) { (char) str[i], '\0' } );

            //add token to args
            //printf("added char to token, token:%s\n", token);

        }
    }
    char** argv = malloc(80*80);
    argv = args;
    return argv;
}

int main(int argc, char** argv)
{
    printf("start program\n");
    char** args = split(" cp test.c test1.c ");
    for (int j = 0; j < 3; j++ )
    {
          printf("%s\n", args[j]);
    }
}

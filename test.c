#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char** split(const char* str)
{
    printf("entering split, for string: %s", str);
    int argc = 0;
    char* token = "";
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i]==' ')
        {
            if (strlen(token)!=0)
            {
                argc++;
            }
        }
        else
        {
            printf("adding char to token");
            token = strcat(token, (char[2]) { (char) str[i], '\0' } );
            printf("added char to token");

        }
    }
    //defintely wrong
    //char** args = char[argc][80];
    char **args = malloc(80);
    argc = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i]!=' ')
        {
            //apend str[i] (char) to token if not space
            printf("adding char to token");
            char* token = strcat(token, (char[2]) { (char) str[i], '\0' } );
            printf("added char to token");
        }
        else
        {
            args[argc] = token;
            argc++;
        }
    }
    return args;
}

int main(int argc, char** argv)
{
    printf("start program");
    char** args = split("cp test.c test1.c");
    for (int j = 0; j < 10; j++ )
    {
          printf("%s", args[j]);
    }
}

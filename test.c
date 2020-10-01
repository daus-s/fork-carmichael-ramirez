#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

char** split(const char* str)
{
    int start_previous = 0;
    char** args;//asfkjbaskjfbaskj askjnfkasjnfkasjnfajnfkasjnfkjsa
    int argc = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i]==' ')
        {
            if (i!=start_previous)
            {
                char* token = str[start_previous:i];
                args[argc] = token;
                argc++;

            }
            else
            {
                start_previous = i + 1;
            }
        }
    }
}

int main()
{
    char** args = split("cp test.c test1.c");
    for (int j = 0; j < 10; j++ )
    {
          printf("%s", args[j]);
    }
}

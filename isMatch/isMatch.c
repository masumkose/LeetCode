#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isMatch(char* s, char* p)
{
    if (*p == '\0' && *s == '\0')
        return true;

    
    if ((*s == *p || *p == '.') && *s && *p)
    {
        if (isMatch(s + 1, p + 1))//this is the buffer error
            return (true);
    }

    if (*(p + 1))
    {
        if (*(p + 1) == '*')
        {
            while ((*s == *p || *p == '.') && *s && *p)
            {
                if (*s && *(p + 2))
                {
                    if (isMatch(s, p + 2))
                        return true;
                }
                s++;
            }
            if (*(p + 2) != '\0' && *s != '\0')
            {
                if (isMatch(s , p + 2))
                    return (true);

            }
            else if (*(p + 2) == '\0' && *s == '\0')
                return true;
        }
    }
    return (false);
}

int main()
{

    if (isMatch("a","ab*"))
        printf("TRUE");
    else
        printf("FALSE");


    return 0;
}
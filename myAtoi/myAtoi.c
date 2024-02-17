
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char* s)
{
    long num = 0;
    int i =0;
    int sign = 0;

	while (s[i] == ' ' && s[i])
	{
		i++;
	}
	
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = 1;
        i++;
    }

    while (s[i])
    {
		if (!(s[i] >= '0' && s[i] <= '9'))
			break ;
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
        {
            if (sign == 1)
                return -2147483648;
			else
            	return 2147483647;
        }
    
        num = (s[i] - 48) + num * 10;
        i++;
    }
    if (sign == 1)
        num *= -1;

    return ((int)num);

}


int main()
{

	printf("%d\n", myAtoi("21474836460"));
	return 0;
}

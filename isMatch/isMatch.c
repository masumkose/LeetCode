#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p)
{
	if (*p == '\0' && *s == '\0')
		return true;

	if (*p == '\0')
		return false;

	if (*(p + 1) == '*' && (*s != *p || *p != '.'))
	{
		if (isMatch(s, p + 2))
			return true;
	}
	if ((*s == *p || *p == '.') && *s)
	{	
		if (*(p + 1) == '*')
		{
			if (isMatch(s + 1, p))
				return true;
		}
		if (isMatch(s + 1, p + 1))
			return (true);
	}

	return (false);
}

int main()
{

	if (isMatch("a","ab*"))
		printf("TRUE");
	else
		printf("FALSE");


	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

bool	isPalindrome(int x)
{
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	int i = 0;
	int digit = 0;
	int num[13];

	while (x != 0)
	{
		digit++;
		num[i++] = x % 10;
		x /= 10;
	}
	while (i / 2 > 0)
	{
		if (num[i - 1] != num[digit - i])
			return false;
		i--;
	}
	return true;
}

int main ()
{

	if (isPalindrome(156451))
		printf("TRUE\n");
	else
		printf("FALSE\n");

	return 0;
}

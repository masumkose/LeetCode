
#include <stdlib.h>
#include <stdio.h>


int is_repeat(char *s, char c, int j, int i)
{
	int len = 0;

	while(j >= i)
	{
		if (s[j] == c)
			return (0);
		j--;
	}

	return (1);
}


int lengthOfLongestSubstring(char* s)
{
	int i = 0, j = 0;
	int leng = 0;
	int temp = 0;

	while (s[i])
	{
		temp = 1;
		j = i + 1;
		while (s[j])
		{
			if (is_repeat(s, s[j], j - 1, i) == 0)
				break;
			j++;
			temp++;
		}
		if (temp  > leng)
			leng = temp;
		i++;
	}
	return (leng);
}


int main()
{
	char s[] = "muhammetasua";
	int x = lengthOfLongestSubstring(s);





	printf("%d\n", x);
	return (0);
}

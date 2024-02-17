
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s)
{
	if (!s)
		return (0);
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int is_palindrome(char *s, int newlen)
{
	int i = 0;
	while (i < newlen / 2)
	{
		if (s[i] != s[newlen - 1 - i])
			return (0);
		i++;
	}
	return (newlen);
}

char *giveme_palindrome(char *s, int newlen)
{
	char *palind = malloc(sizeof(char) * newlen + 1);
	int i = 0;
	while (i < newlen)
	{
		palind[i] = s[i];
		i++;
	}
	palind[i] = '\0';
	return (palind);
}


char *longestPalindrome(char *s)
{
	int		i = 0;
	int		j = 0;
	int		m = 0;
	int 	c = 0;
	char	*palind = NULL;
	int len = ft_strlen(s);

	while (s[i])
	{
		j = 0;
		while (j <= len - i)
		{
			if ((c = is_palindrome(s + i, j)))
			{
				if (ft_strlen(palind) < c)
					palind = strndup(s + i, j);
			}
			j++;
		}
		i++;
	}

	return palind;
}

int main()
{
	char s[] = "musudfgddgfdusufgm";


	//printf("%d", is_palindrome(s + 1 , 4));
	printf("%s", longestPalindrome(s));


	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char	*longestCommonPrefix(char **strs, int strsSize)
{
	char	*common;
	int i = 0;
	int j = 0;
	int m = 0;

    if (strsSize == 1)
        return (strs[0]);
	while (i < strsSize - 1)
	{
		j = 0;
		if (strs[i][j] == '\0' || strs[i][j] == '\0')
			return ("");
		while (strs[i][j] == strs[i + 1][j] && strs[i][j] != '\0' && strs[i + 1][j] != '\0')
		{
			j++;
		}
		if (i == 0 || j < m)
			m = j;
		if (m == 0)
			return ("");
		i++;
	}
	common = malloc (sizeof(char) + (m + 1));
	if (common == NULL)
		return NULL;
	strncpy(common,strs[0],m);
	common[m] = '\0';
	return (common);
}




int main()
{
	char *s[] = {"flower","flower","flower","flower"};

	printf("LCP == %s\n", longestCommonPrefix(s, sizeof(s) / sizeof(char *)));


	return (0);
}

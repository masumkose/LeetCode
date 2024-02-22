#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int	basamak_sayar(int n)
{
	int	basamak;

	if (n == 0)
		return (1);
	basamak = 0;
	while (n != 0)
	{
		n /= 10;
		basamak++;
	}
	return (basamak);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			basamak;
	long int	new;

	new = n;
	basamak = basamak_sayar(n);
	if (n < 0)
	{
		new = new * -1;
		basamak++;
	}
	str = (char *) malloc((basamak + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[basamak] = 0;
	while (basamak > 0)
	{
		str[basamak - 1] = new % 10 + '0';
		new /= 10;
		basamak--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char* intToRoman(int num)
{
	char	*roman;
	char	*strnum;
	int		i = 0;
	int		j = 0;


	roman = malloc (sizeof(char) * 256);


	strnum = ft_itoa(num);
	int		size = strlen(strnum);


		if (size == 4) // 1000
		{
			if (strnum[i] - 48 == 1)
				roman[j++] = 'M';
			else if (strnum[i] - 48 == 2)
			{
				roman[j++] = 'M';
				roman[j++] = 'M';
			}
			else if (strnum[i] - 48 == 3)
			{
				roman[j++] = 'M';
				roman[j++] = 'M';
				roman[j++] = 'M';
			}
			size--;
			i++;
		}
		if (size == 3) //100
		{
			if  (strnum[i] - 48 == 1)
				roman[j++] = 'C';
			else if  (strnum[i] - 48 == 2)
			{
				roman[j++] = 'C';
				roman[j++] = 'C';
			}
			else if  (strnum[i] - 48 == 3)
			{
				roman[j++] = 'C';
				roman[j++] = 'C';
				roman[j++] = 'C';
			}
			else if  (strnum[i] - 48 == 4)
			{
				roman[j++] = 'C';
				roman[j++] = 'D';
			}
			else if  (strnum[i] - 48 == 5)
			{
				roman[j++] = 'D';
			}
			else if  (strnum[i] - 48 == 6)
			{
				roman[j++] = 'D';
				roman[j++] = 'C';
			}
			else if  (strnum[i] - 48 == 7)
			{
				roman[j++] = 'D';
				roman[j++] = 'C';
				roman[j++] = 'C';
			}
			else if  (strnum[i] - 48 == 8)
			{
				roman[j++] = 'D';
				roman[j++] = 'C';
				roman[j++] = 'C';
				roman[j++] = 'C';
			}
			else if (strnum[i] - 48 == 9)
			{
				roman[j++] = 'C';
				roman[j++] = 'M';
			}
			size--;
			i++;
		}
		if (size == 2) // 10
		{
			if  (strnum[i] - 48 == 1)
				roman[j++] = 'X';
			else if  (strnum[i] - 48 == 2)
			{
				roman[j++] = 'X';
				roman[j++] = 'X';
			}
			else if  (strnum[i] - 48 == 3)
			{
				roman[j++] = 'X';
				roman[j++] = 'X';
				roman[j++] = 'X';
			}
			else if  (strnum[i] - 48 == 4)
			{
				roman[j++] = 'X';
				roman[j++] = 'L';
			}
			else if  (strnum[i] - 48 == 5)
			{
				roman[j++] = 'L';
			}
			else if  (strnum[i] - 48 == 6)
			{
				roman[j++] = 'L';
				roman[j++] = 'X';
			}
			else if  (strnum[i] - 48 == 7)
			{
				roman[j++] = 'L';
				roman[j++] = 'X';
				roman[j++] = 'X';
			}
			else if  (strnum[i] - 48 == 8)
			{
				roman[j++] = 'L';
				roman[j++] = 'X';
				roman[j++] = 'X';
				roman[j++] = 'X';
			}
			else if (strnum[i] - 48 == 9)
			{
				roman[j++] = 'X';
				roman[j++] = 'C';
			}
			size--;
			i++;
		}
		if (size == 1) // 1
		{
			if  (strnum[i] - 48 == 1)
				roman[j++] = 'I';
			else if  (strnum[i] - 48 == 2)
			{
				roman[j++] = 'I';
				roman[j++] = 'I';
			}
			else if  (strnum[i] - 48 == 3)
			{
				roman[j++] = 'I';
				roman[j++] = 'I';
				roman[j++] = 'I';
			}
			else if  (strnum[i] - 48 == 4)
			{
				roman[j++] = 'I';
				roman[j++] = 'V';
			}
			else if  (strnum[i] - 48 == 5)
			{
				roman[j++] = 'V';
			}
			else if  (strnum[i] - 48 == 6)
			{
				roman[j++] = 'V';
				roman[j++] = 'I';
			}
			else if  (strnum[i] - 48 == 7)
			{
				roman[j++] = 'V';
				roman[j++] = 'I';
				roman[j++] = 'I';
			}
			else if (strnum[i] - 48 == 8)
			{
				roman[j++] = 'V';
				roman[j++] = 'I';
				roman[j++] = 'I';
				roman[j++] = 'I';
			}
			else if (strnum[i] - 48 == 9)
			{
				roman[j++] = 'I';
				roman[j++] = 'X';
			}
			size--;
			i++;
		}
	roman[j] = '\0';
	return (roman);
}





int main()
{



	printf("%s\n", intToRoman(3888));


	return (0);
}

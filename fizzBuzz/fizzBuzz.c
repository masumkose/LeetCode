

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	basamak_sayar(int i)
{
	int digit = 0;

	while (i /= 10)
	{
		digit++;
	}
	return digit + 1;
}


char	*ft_itoa(int i)
{
	char *num;
	int	size = basamak_sayar(i);
	num = malloc (sizeof(char) * size + 1);
	num[size] = '\0';
	while (size != 0)
	{
		num[size - 1] = (i % 10) + '0';
		i /= 10;
		size--;
	}
	return (num);
}


char** fizzBuzz(int n, int* returnSize)
{
	char **result;
	*returnSize = n;
	int i = 1;
	result = malloc (sizeof(char *) * (n + 1));
	while (i <= n)
	{
		if (i % 3 == 0 && i % 5 == 0)
			result[i - 1] = strdup("FizzBuzz");
		else if (i % 3 == 0)
			result[i - 1] = strdup("Fizz");
		else if (i % 5 == 0)
			result[i - 1] = strdup("Buzz");
		else
			result[i - 1] = ft_itoa(i);

		i++;
	}
	result[n] = NULL;

	return (result);
}


int	main()
{

	char **result;
	int i = 0;

	int	size;


	result = fizzBuzz(3, &size);
	while (result[i])
		printf("%s\n", result[i++]);



	return (0);
}

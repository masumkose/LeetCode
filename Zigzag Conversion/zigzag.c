#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char *convert(char *s, int numRows)
{
	if (numRows <= 1 || !s) // No conversion needed if numRows <= 1
		return s;

	int len = strlen(s);
	char **array = malloc(sizeof(char *) * numRows);

	for (int i = 0; i < numRows; i++) {
		array[i] = malloc(sizeof(char) * (len + 1)); // +1 for null terminator
		memset(array[i], 0, sizeof(char) * (len + 1)); // Initialize array with null characters
	}

	int row = 0, step = 1;

    for (int i = 0; i < len; i++)
	{
		array[row][i] = s[i];
		if (row == 0)
			step = 1;
		else if (row == numRows - 1)
			step = -1;
		row += step;
	}

	char *newstr = malloc(sizeof(char) * (len + 1)); // +1 for null terminator
	int index = 0;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (array[i][j] != 0) // Append non-null characters to newstr
				newstr[index++] = array[i][j];
		}
		free(array[i]); // Free memory allocated for each row
	}

	free(array); // Free memory allocated for the array of rows
	newstr[len] = '\0'; // Null-terminate the new string
	return newstr;
}*/


char *convert(char *s, int numRows)
{
	if (!s || numRows<= 1)
		return (s);

	char **array;
	char *newstr;
	int i = 0, j = 0, len = 0, step = 1, row = 0, index = 0;

	len = strlen(s);
	array = malloc (sizeof(char *) * numRows + 1);
	while (i < numRows)
	{
		array[i] = malloc (sizeof(char) * len + 1);
		i++;
	}

	for (i = 0; i < len; i++)
	{
		array[row][i] = s[i];
		if (row == 0)
			step = 1;
		else if (row == numRows - 1)
			step = -1;
		row += step;
	}

	newstr = malloc (sizeof(char) * (len + 1));
	for (i = 0; i < numRows; i++)
	{
		for(j = 0; j < len; j++)
		{
			if (array[i][j] != 0)
			{
				newstr[index] = array[i][j];
				index++;
			}
		}
	}
	newstr[len] = 0;

	return (newstr);
}



int main ()
{
	printf("%s\n", convert("PAYPALISHIRING", 3));
	return 0;
}

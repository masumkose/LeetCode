#include <stdio.h>
#include <stdlib.h>

char** letterCombinations(char* digits, int* returnSize)
{
    char **result;
    int i = 0;

    result = malloc (sizeof(char *) * 50);
    while (digits[i])
    {
        result[i] = malloc (sizeof(char) * returnSize[i]);
        i++;
    }




    return (result);
}



int main()
{
    char digits[] = "23";
    int returnsize[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    char **result = letterCombinations(digits, returnsize);
    int i = 0;
    while (result[i])
        printf("%s\n",result[i++]);

    return 0;
}
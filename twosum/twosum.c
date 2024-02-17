/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include <stdlib.h>

int *twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int n = 0;
    int m = 0;
    int temp = 0;


    int *result = malloc (sizeof(int ) * (2));
    if (result == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    while (n < numsSize)
    {
        m = n + 1;
        while (m < numsSize)
        {
            if (nums[m] + nums[n] == target)
            {
                result[0] = n;
                result[1] = m;
                *returnSize = 2;
                return (result);
            }
            m++;
        }
        n++;
    }
    *returnSize = 0;
    return (NULL);
}

/* int main (int ac, char *argv[])
{
    int nums[] = {1, 2, 3, 4, 5 ,6 ,7, 8, 9};
    int numsize = 9;
    int target = 5;
    int *returnsize;


    twoSum(nums, numsize, target, returnsize);

    // printf()

    return (0);
}  */

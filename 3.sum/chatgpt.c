#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    int **result = NULL;
    *returnColumnSizes = NULL;
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) // Terminate loop if current element > 0
            break;
        if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicates
            continue;

        int target = -nums[i];
        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                // Found a triplet
                (*returnSize)++;
                result = realloc(result, sizeof(int *) * (*returnSize));
                result[*returnSize - 1] = malloc(sizeof(int) * 3);
                result[*returnSize - 1][0] = nums[i];
                result[*returnSize - 1][1] = nums[left];
                result[*returnSize - 1][2] = nums[right];

                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    // Set column sizes
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}

int main() {
    int nums[] = {-1, 0, 1, 2, 3, -3, 5, -4};
    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **result = threeSum(nums, sizeof(nums) / sizeof(nums[0]), &returnSize, &returnColumnSizes);

    if (result != NULL) {
        for (int m = 0; m < returnSize; m++) {
            printf("Result %d:\n", m);
            printf("[0] == %d, ", result[m][0]);
            printf("[1] == %d, ", result[m][1]);
            printf("[2] == %d\n", result[m][2]);
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}

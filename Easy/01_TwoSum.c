#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100
#define RETURN_SIZE 2

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
void printReturnArray(int *returnArray, int returnSize);

int main(void)
{
    int nums[MAX_ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    int numsSize = 10;
    int target = 5;
    int returnSize = 2;
    int *returnArray = twoSum(nums, numsSize, target, &returnSize);
    printReturnArray(returnArray, returnSize);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *returnArray = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }
    return returnArray;
}

void printReturnArray(int *returnArray, int returnSize)
{
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", returnArray[i]);
    }
    printf("\n");
}
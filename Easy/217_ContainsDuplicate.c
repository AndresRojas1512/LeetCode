#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize);

int main(void)
{
    int nums[10] = {1, 2, 3, 1};
    int numsSize = 4;
    if (containsDuplicate(nums, numsSize))
        printf("True, hay repetidos\n");
    else
        printf("False, all are different\n");
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int* nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
}
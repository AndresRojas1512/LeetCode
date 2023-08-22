#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize);

int main(void)
{
    int nums[10] = {1, 2, 3, 3, 3, 4, 5};
    int numsSize = 7;
    int count = removeDuplicates(nums, numsSize);
    printf("%d\n", count);
    return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    int insertIndex = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i - 1] != nums[i])
        {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    return insertIndex;
}
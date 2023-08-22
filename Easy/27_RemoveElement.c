#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100

int main(void)
{
    int nums[MAX_ARRAY_SIZE] = {3, 2, 2, 3};
    int numsSize = 4;
    int val = 3;
    int returnVal = removeElement(nums, numsSize, val);
    printf("%d\n", returnVal);
    return 0;
}

int removeElement(int *nums, int numsSize, int val)
{
    int retVal = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[retVal++] = nums[i];
        }
    }
    return retVal;
}
#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target)
{
    int count = 0;
    recCalc(nums, numsSize, target, 0, 0, &count);
    return count;
}

void recCalc(int *nums, int numsSize, int target, int curIndex, int curSum, int *count)
{
    if (curIndex == numsSize) // We have passed by 1 the limit of the array/ (We are out the boundary of the array)
    {
        if (curSum == target)
        {
            (*count)++;
        }
    }
    else
    {
        recCalc(nums, numsSize, target, curIndex + 1, curSum + nums[curIndex], count);
        recCalc(nums, numsSize, target, curIndex + 1, curSum - nums[curIndex], count);
    }
}
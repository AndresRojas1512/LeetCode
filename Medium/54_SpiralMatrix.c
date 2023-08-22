#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int left = 0;
    int top = 0;
    int bottom = matrixSize - 1;
    int right = *matrixColSize - 1;
    
    int *returnArray = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;

    while (top <= bottom && left <= right)
    {
        // get values from top row (from left to right)
        for (int i = left; i <= right; i++)
        {
            returnArray[(*returnSize)++] = matrix[top][i];
        }
        top++;
        // get values from right column (from up to to down)
        for (int i = top; i <= bottom; i++)
        {
            returnArray[(*returnSize)++] = matrix[i][right];
        }
        right--;
        if (top <= bottom)
        {
            // get values from bottom row (from right to left)
            for (int i = right; i >= left; i--)
            {
                returnArray[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }
        if (left <= right)
        {
            // get values from left colum (from bottom to top)
            for (int i = bottom; i >= top; i--)
            {
                returnArray[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    return returnArray;
}
#include <stdio.h>
#include <stdlib.h>

// Crossing pointers NeetCode
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    // Malloc the matrix
    int **matrix = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
        matrix[i] = malloc(sizeof(int) * n);
    }

    // Helper pointers
    int left = 0;
    int top = 0;
    int right = n - 1;
    int bottom = n - 1;

    // Fill Number
    int fillNumber = 1;
    while (left <= right)
    {
        // fill the top row from left to right
        for (int i = left; i <= right; i++, fillNumber++)
        {
            matrix[top][i] = fillNumber;
        }
        top++;
        // fill the right column from top to bottom
        for (int i = top; i <= bottom; i++, fillNumber++)
        {
            matrix[i][right] = fillNumber;
        }
        right--;
        // fill the bottom row from right to left
        for (int i = right; i >= left; i--, fillNumber++)
        {
            matrix[bottom][i] = fillNumber;
        }
        bottom--;
        // fill the left column from bottom to top
        for (int i = bottom; i >= top; i--, fillNumber++)
        {
            matrix[i][left] = fillNumber;
        }
        left++;
    }
    return matrix;
}
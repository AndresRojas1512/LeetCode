#include <stdio.h>
#include <stdlib.h>
typedef int matrix[10][10];

int main(void)
{
    matrix mtrx = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return 0;
}

void rotate(int** matrix, int matrixSize)
{
    int left = 0;
    int right = matrixSize - 1;
    while (left < right)
    {
        for (int i = 0; i < (right - left); i++)
        {
            int top = left;
            int bottom = right;
            // save the top left
            int topLeft = matrix[top][left + i];
            // move the bottom left into top left
            matrix[top][left + i] = matrix[bottom - i][left];
            // move bottom right into bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];
            // move top right into bottom right
            matrix[bottom][right - i] = matrix[top + i][right];
            // move top left left into top right
            matrix[top + i][right] = topLeft;
        }
        right -= 1;
        left += 1;
    }
}


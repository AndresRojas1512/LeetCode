#include <stdio.h>
#include <stdlib.h>

typedef int matrix[10][10];
void setZeroes(matrix matrix, int matrixSize, int* matrixColSize)
{
    int rows = matrixSize;
    int columns = *matrixColSize;
    int rowZero = 1;
    // determine which rows/cols need to be zero
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (matrix[r][c] == 0)
            {
                matrix[0][c] = 0; // set to zero
                if (r > 0)
                {
                    matrix[r][0] = 0; // set to zero
                }
                else
                {
                    rowZero = 0; // set extra memory block to zero
                }
            }
        }
    }
    for (int r = 1; r < rows; r++) // skip the first row and the first column. Because of the intersection of the internal arrays
    {
        for (int c = 1; c < columns; c++)
        {
            if (matrix[0][c] == 0 || matrix[r][0] == 0)
            {
                matrix[r][c] = 0;
            }

        }
    }
    if (matrix [0][0] == 0)
    {
        for (int r = 0; r < rows; r++)
        {
            matrix[r][0] = 0;
        }
    }
    // Now we handle the extra memory block for setting the first row to zero
    if (!rowZero)
    {
        for (int c = 0; c < columns; c++)
        {
            matrix[0][c] = 0;
        }
    }
}

void printMatrix(matrix mtrx, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mtrx[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    matrix mtrx = {{1, 1, 1}, {0, 0, 0}, {1, 1, 1}};
    int r = 3;
    int c = 3;
    printMatrix(mtrx, r, c);
    printf("\n");
    setZeroes(mtrx, r, &c);
    printMatrix(mtrx, r, c);
    return 0;
}
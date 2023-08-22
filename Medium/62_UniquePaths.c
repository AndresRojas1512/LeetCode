#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    int resultVal = 1;
    // Allocate a dynamic matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Fill the first column with zeros
    for (int i = 0; i < m; i++)
    {
        matrix[i][0] = 1;
    }

    // Fill the first row with zeros
    for (int j = 0; j < n; j++)
    {
        matrix[0][j] = 1;
    }

    // Compute the values of the rest of the matrix
    for (int i = 1; i < m; i ++)
    {
        for (int j = 1; j < n; j++)
        {
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        }
    }

    resultVal = matrix[m - 1][n - 1];
    // Free space
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return resultVal;
}
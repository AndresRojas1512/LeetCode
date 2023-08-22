#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMax(int a, int b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

int longestCommonSubsequence(char * text1, char * text2)
{
    int resultVal = 0;
    int m = strlen(text1);
    int n = strlen(text2);
    // Create the grid
    int **grid = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++)
    {
        grid[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    // Fill the grid with 0's
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            grid[i][j] = 0;
        }
    }
    // Iterate through the grid in reverse order and compute the values
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j]) // If characters match each other
            {
                grid[i][j] = 1 + grid[i + 1][j + 1]; // 1 = match; grid[i + 1][j + 1] = diagonal
            }
            else // If they dont match
            {
                grid[i][j] = findMax(grid[i][j + 1], grid[i + 1][j]); // Look for the max between right and down value. We do not add 1 because the character do not match each other
            }
        }
    }
    resultVal = grid[0][0]; // The result is at the top left
    // Free the memory
    for (int i = 0; i < m + 1; i++)
    {
        free(grid[i]);
    }
    free(grid);
    return resultVal;
}
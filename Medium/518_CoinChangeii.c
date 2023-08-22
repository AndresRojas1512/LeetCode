#include <stdio.h>
#include <stdlib.h>

int change(int amount, int *coins, int coinsSize)
{
    int result;
    // Create grid
    int **grid = (int **)malloc((amount + 1) * sizeof(int *));
    for (int i = 0; i < (amount + 1); i++)
    {
        grid[i] = (int *)malloc((coinsSize + 1) * sizeof(int));
    }
    // Fill with zeros all the grid
    for (int i = 0; i < (amount + 1); i++)
    {
        for (int j = 0; j < (coinsSize + 1); j++)
        {
            grid[i][j] = 0;
        }
    }
    // Fill with ones the first row
    for (int j = 0; j < (coinsSize + 1); j++)
    {
        grid[0][j] = 1;
    }
    // Computations
    for (int i = 1; i < (amount + 1); i++)
    {
        for (int j = (coinsSize - 1); j >= 0; j--)
        {
            grid[i][j] = grid[i][j + 1];
            if (i - coins[j] >= 0)
            {
                grid[i][j] += grid[i - coins[j]][j];
            }
        }
    }
    result = grid[amount][0];
    // Free memory
    for (int i = 0; i < (amount + 1); i++)
    {
        free(grid[i]);
    }
    free(grid);
    return result;
}

int main(void)
{
    int result = 0;
    int coins[3] = {1, 2, 5};
    int coinsSize = 3;
    int amount = 5;
    result = change(amount, coins, coinsSize);
    printf("%d\n", result);
    return 0;
}
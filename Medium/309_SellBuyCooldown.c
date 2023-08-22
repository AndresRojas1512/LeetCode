#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// State: Buying or Selling
// If buy -> i + 1
// If sell -> i + 2

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize <= 1) // 1 day or 0 days -> no profit
        return 0;
    int A = 0;
    int B = -prices[0];
    int C = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        int prev = A;
        A = max(A, C);
        C = B + prices[i];
        B = max(B, prev - prices[i]);
    }
    return max(A, C);
}
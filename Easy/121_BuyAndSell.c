#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int* prices, int pricesSize);

int main(void)
{
    int prices[MAX_ARRAY_SIZE] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int topProfit = maxProfit(prices, pricesSize);
    printf("%d\n", topProfit);
    return 0;
}

int maxProfit(int *prices, int pricesSize)
{
    int min = prices[0];
    int profit = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] > min)
        {
            profit = max(profit, prices[i] - min);
        }
        else
        {
            min = prices[i];
        }
    }
    return profit;
}
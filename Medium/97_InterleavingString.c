#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    if ((len1 + len2) != len3)
    {
        return false;
    }
    // Allocate the grid
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i < (len1 + 1); i++)
    {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    // Fill all the dp as False
    for (int i = 0; i < (len1 + 1); i++)
    {
        for (int j = 0; j < (len2 + 1); j++)
        {
            dp[i][j] = false;
        }
    }
    // Initialize the corner value as True
    dp[len1][len2] = 1;
    //We are going to start at the right-bottom corner up to the left-up corner
    for (int i = len1; i >= 0; i--)
    {
        for (int j = len2; j >= 0; j--)
        {
            if ((i < len1) && (s1[i] == s3[i + j]) && dp[i + 1][j])
            {
                dp[i][j] = true;
            }
            if ((j < len2) && (s2[j] == s3[i + j]) && dp[i][j + 1])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[0][0];
}
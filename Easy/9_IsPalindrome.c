#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(void)
{
    int x = 10;
    if (isPalindrome(x))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

bool isPalindrome(int x)
{
    int copyX = x;
    int remainder;
    int reversed = 0;
    if (x < 0)
    {
        return false;
    }
    else
    {
        while (copyX != 0)
        {
            remainder = copyX % 10;
            reversed = reversed * 10 + remainder;
            copyX /= 10;
        }
    }
    if (reversed == x)
        return true;
    else
        return false;
}
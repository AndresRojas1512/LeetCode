#include <stdio.h>
#include <stdlib.h>

int main(void)
{

}

char *longestCommonPrefix(char **strs, int strsSize)
{
    for (int i = 0;; i++)
    {
        if (strs[0][i] == '\0')
            return strs[0];
        else
        {
            for (int j = 1; j < strsSize; j++)
            {
                if (strs[0][i] != strs[j][i])
                {
                    return strs[0][i] = '\0';
                }
            }
        }
    }
}
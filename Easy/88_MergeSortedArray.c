#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i, j, k; // i for nums1, j for nums2, k for nums1 the new formed array
    i = m - 1; // index pointing to the last element of nums1
    j = n - 1; // index pointing to the last element of nums2
    k = n + m - 1; // index pointing to the last element of nums1 (final modified array)
    for (; i >= 0 && j >= 0 && k >= 0; k--)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
    }
    if (k >= 0)
    {
        for (;j >= 0 && k >= 0; j--, k--)
        {
            nums1[k] = nums2[k];
        }
    }
}
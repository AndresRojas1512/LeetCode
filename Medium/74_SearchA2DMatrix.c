#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Solution O(log M * N)

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int rows = matrixSize;
    int columns = *matrixColSize;

    // Pointers for binary search applyied to rows
    int top = 0;
    int bottom = rows - 1;
    while (top <= bottom)
    {
        int row = (top + bottom) / 2;
        if (target > matrix[row][(*matrixColSize) - 1])
        {
            top = row + 1; // we make the limits smaller by moving the top down.
        }
        else if (target < matrix[row][0])
        {
            bottom = row - 1;
        }
        else // when the target falls into the current row (the middle row)
        {
            break;
        }
    }
    // For the case when 
    if (!(top <= bottom)) // check if the pointers crossed, that means that target is not in the matrix
    {
        return false;
    }
    // Now we run binary search in the row that should have the target
    int row = (top + bottom) / 2;
    int left = 0;
    int right = columns - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (target > matrix[row][middle]) // that means that we have to search in the right portion of the row
        {
            left = middle + 1;
        }
        else if (target < matrix[row][middle])
        {
            right = middle - 1;
        }
        else // if we found it
        {
            return true;
        }
        // if we exit the while loop and never returned true, return false outside the loop
    }
    return false;
}
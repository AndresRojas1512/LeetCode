#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *arrayToBST(int *nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    int mid = (right + left) / 2;
    struct TreeNode *root = createNode(nums[mid]);
    root->left = arrayToBST(nums, left, mid - 1);
    root->right = arrayToBST(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return arrayToBST(nums, 0, numsSize - 1);
}
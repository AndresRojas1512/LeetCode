#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode *root, int *array, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, array, returnSize);
    array[(*returnSize)++] = root->val;
    inorder(root->right, array, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int *array = (int *)malloc(100 * sizeof(int));
    inorder(root, array, returnSize);
    return array;
}
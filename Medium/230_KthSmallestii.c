#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getTreeSize(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = getTreeSize(root->left);
    int right = getTreeSize(root->right);
    return 1 + left + right;
}

void Search(struct TreeNode* root, int *stack, int *index)
{
    if (root == NULL)
    {
        return;
    }
    Search(root->left, stack, index);
    stack[(*index)++] = root->val;
    Search(root->right, stack, index);
}

int kthSmallest(struct TreeNode* root, int k)
{
    int treeSize = getTreeSize(root);
    int *stack = (int *)malloc(treeSize * sizeof(int));
    int index = 0;
    Search(root, stack, &index);
    int result = stack[k - 1];
    free(stack);
    return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool valid(struct TreeNode *node, double left, double right)
{
    if (node == NULL)
    {
        return true; // an empty binary tree is valid
    }
    if (!(node->val < right && node->val > left))
    {
        return false;
    }
    return (valid(node->left, left, node->val) && valid(node->right, node->val, right));
}

bool isValidBST(struct TreeNode* root)
{
    return valid(root, -INFINITY, INFINITY);
}

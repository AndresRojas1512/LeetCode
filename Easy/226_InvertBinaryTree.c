#include <stdio.h>
#include <stdlib.h>

// DFS
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    // Swap the children
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
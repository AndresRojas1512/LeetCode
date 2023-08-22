#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int low, int high)
{
    if (root == NULL)
    {
        return root;
    }
    int sum = 0;
    if (root->val > low)
    {
        sum += rangeSumBST(root->left, low, high);
    }
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
    }
    if (root->val < high)
    {
        sum += rangeSumBST(root->right, low, high);
    }
    return sum;
}
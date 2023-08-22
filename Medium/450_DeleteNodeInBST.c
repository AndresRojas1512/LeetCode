#include <stdio.h>
#include <stdlib.h>

// Not finished
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->val)
    {
        root->left = (root->left, key);
    }
    else if (key > root->val)
    {
        root->right = (root->right, key);
    }
    else // Found the Node that we want to delete
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        // Find the minimum from the right subtree
        struct TreeNode *curr = root->right;
        while (curr->left)
        {
            curr = curr->left;
        }
        root->val = curr->val;
        root->right = (root->right, root->val);
    }
    return root;
}
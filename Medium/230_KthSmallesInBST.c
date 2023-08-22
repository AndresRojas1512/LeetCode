#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct StackElement
{
    struct TreeNode *node;
    struct StackElement *next;
};

// Done
struct StackElement *createStackElement(struct TreeNode *bstNode)
{
    struct StackElement *newElement = (struct StackElement *)malloc(sizeof(struct StackElement));
    newElement->node = bstNode;
    newElement->next = NULL;
    return newElement;
}

// Done
void push(struct StackElement **top, struct TreeNode *bstNode)
{
    if (*top == NULL)
    {
        struct StackElement *newStackElement = createStackElement(bstNode);
        *top = newStackElement;
    }
    else
    {
        struct StackElement *newStackElement = createStackElement(bstNode);
        newStackElement->next = *top;
        *top = newStackElement;
    }
}

// Done
struct TreeNode *pop(struct StackElement **top)
{
    if (*top == NULL)
    {
        return NULL;
    }
    struct StackElement *temp;
    temp = *top;
    *top = (*top)->next;
    return temp->node;
}

// Done
bool isEmpty(struct StackElement *top)
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int kthSmallest(struct TreeNode* root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    int n = 0;
    struct TreeNode *cur = root;
    struct StackElement *top = NULL; // Empty Stack
    while (cur != NULL && !isEmpty(top))
    {
        while (cur != NULL) // keep going left
        {
            push(&top, cur);
            cur = cur->left;
        }
        cur = pop(&top);
        n++;
        if (n == k)
        {
            return cur->val;
        }
        cur = cur->right;
    }
}
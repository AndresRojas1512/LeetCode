#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNewNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return createNewNode(head->val);
    }
    // Create two pointers in the list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *mid = slow;
    while (fast != NULL && fast->next != NULL)
    {
        mid = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode *root = createNewNode(slow->val);
    mid->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}

int main(void)
{
    return 0;
}
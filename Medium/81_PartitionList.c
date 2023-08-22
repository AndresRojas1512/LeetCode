#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
    // Create left dummy list
    struct ListNode *left = (struct ListNode *)malloc(sizeof(struct ListNode));
    left->val = 0;
    left->next = NULL;

    // Create right dummy list
    struct ListNode *right = (struct ListNode *)malloc(sizeof(struct ListNode));
    right->val = 0;
    right->next = NULL;

    // Create the tails of both new lists
    struct ListNode *leftTail = left;
    struct ListNode *rightTail = right;

    while (head)
    {
        if (head->val < x)
        {
            leftTail->next = head;
            leftTail = leftTail->next;
        }
        else
        {
            rightTail->next = head;
            rightTail = rightTail->next;
        }
        head = head->next;
    }
    leftTail->next = right->next;
    rightTail->next = NULL;
    return left->next;
}


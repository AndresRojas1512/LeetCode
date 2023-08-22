#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Solution 1: Long
int getLen(struct ListNode *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}

struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    struct ListNode *temp = head;
    struct ListNode *ptr = head;
    if (!head) // head is null (empty list)
        return NULL;
    if (!head->next) // Only one element in the list
        return head;
    int count = getLen(head);
    k = k % count; // mod of k to find the minimum no. of rotations
    while (k--)
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head; // right now temp should be at the last node, so we make -nextfield to point ot head. Now the list is circular
        // Now is needed to make the temp = head;
        head = temp;
        ptr = temp;
        while (temp->next != head)
            temp = temp->next;
        temp->next = NULL;
        temp = ptr;
    }
    return head;
}
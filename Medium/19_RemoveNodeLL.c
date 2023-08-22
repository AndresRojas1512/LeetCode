#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Two pass
int lenList(struct ListNode *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}
// 1 2 3 4 5 6 7 
// n = 2, len = 7, count = 5
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (!head || !head->next) // lista vacia
        return NULL;
    int len = lenList(head);
    if (len == n)
        return head->next;
    struct ListNode *ptr = head;
    int count = len - n;
    while (count > 1)
    {
        ptr = ptr->next;
        count--;
    }
    struct ListNode *q = ptr->next;
    ptr->next = ptr->next->next;
    free(q);
    return head;
}

// Code One Pass
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    // case when the list has to elements
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (!fast)
        return head->next;
    // continue the code
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *q = slow->next;
    slow->next = slow->next->next;
    free(q);
    return head;
}
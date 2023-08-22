#include <stdio.h>
#include <stdlib.h>

// Not finished
struct ListNode
{
    int val;
    struct ListNode *next;
};

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

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    if (!head)
        return head;
    struct ListNode *curr = head;
    int len = getLen(head);
    int width = len / k;
    int rem = len % k;


}
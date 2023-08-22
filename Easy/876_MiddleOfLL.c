#include <stdio.h>
#include <stdlib.h>
// Not finished
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    if (head == NULL)
        return NULL;
    else
    {
        while (p2 != NULL && p2->next != NULL)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
    }
}
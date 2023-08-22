#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p, *q = head, *r;
    if(head == NULL || head->next == NULL)
        return head;
    p = head->next;
    while(p != NULL)
    {
        if(q == head)
        {
            head->next = p->next;
            p->next = head;
            head = p;
            r = head->next;
            if(r->next != NULL)
            {
                q = r->next;
                p = q->next;
            }
            else
                p = NULL;
        }
        else
        {
            r->next = p;
            q->next = p->next;
            r = p->next = q;
            q = q->next;
            if(q != NULL)
                p = q->next;
            else
                p = NULL;
        }
    }
    return head;
}
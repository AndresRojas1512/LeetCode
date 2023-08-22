#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy;
    dummy->next = head;
    while(head)
    {
        if (head->next && (head->val == head->next->val))
        {
            // skip the nodes that are equal
            while (head->next && (head->val == head->next->val))
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *ptr = result;
    result->val = 0;
    result->next = NULL;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int a = (l1 == NULL) ? 0 : l1->val;
        int b = (l2 == NULL) ? 0 : l2->val;
        ptr->val = a + b + carry;
        carry = ptr->val / 10; // llevamos
        ptr->val = ptr->val % 10;
        if (l1 != NULL)
        {
            l1 = (l1->next == NULL) ? NULL : l1->next;
        }
        if (l2 != NULL)
        {
            l2 = (l2->next == NULL) ? NULL : l2->next;
        }
        if (l1 || l2 || carry) // en el caso que una lista sea mas larga que otra o si es que quedo resto
        {
            ptr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            ptr->next->next = NULL; // NULL porque ya no van a haber mas numeros adelane
            ptr = ptr->next;
        }
    }
    return result;
}
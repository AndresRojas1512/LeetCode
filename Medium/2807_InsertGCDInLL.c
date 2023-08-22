#include <stdio.h>
#include <stdlib.h>

// Not Finished
struct ListNode
{
    int val;
    struct ListNode *next;
};

int getGcd(int a, int b)
{
    int gcd = 1;
    for (int i = 0; (i <= a) && (i <= b); ++i)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *curr = head;
    int currentSum = 0;
    while (head && head->next)
    {
        struct ListNode *midNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode

    }
    
}

// struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
//    if(head==NULL || head->next==NULL) return head;
//     struct ListNode *fir=head;
//     struct ListNode *sec=head->next;
//     int i,n1,n2,gcd;
//     while(sec!=NULL){
//     n1=fir->val; n2=sec->val;
//         for(i=1; i <= n1 && i <= n2; ++i)
//     {
        
//         if(n1%i==0 && n2%i==0)
//             gcd = i;
//     }
//       struct ListNode*np=(struct ListNode*)malloc(sizeof(struct ListNode));
//         np->val=gcd;
//         np->next=sec;
//         fir->next=np;
//         fir=sec;
//         sec=sec->next;
//     }
    
//     return head;
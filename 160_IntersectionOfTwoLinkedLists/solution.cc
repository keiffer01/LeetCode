/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *startA = headA;
        ListNode *startB = headB;
        if (headA == NULL || headB == NULL)
            return NULL;
            
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
            if (headA == NULL && headB == NULL)
                return NULL;
            if (headA == NULL)
                headA = startB;
            if (headB == NULL)
                headB = startA;
        }
        return headA;
    }
};
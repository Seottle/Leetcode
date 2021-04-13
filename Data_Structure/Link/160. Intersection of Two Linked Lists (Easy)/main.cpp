#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 不是走一遍，而是需要一直走，总长度是相等的
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* A = headA;
        ListNode* B = headB;
        while(A != B) { 
            A = A == NULL ? headB : A -> next;
            B = B == NULL ? headA : B -> next;  
        }
        
        return B;
    }
};
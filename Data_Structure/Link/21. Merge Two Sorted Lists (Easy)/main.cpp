#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 合成新链表，一定要给新链表结点 new一个空间！
              然后就是用哨兵去指向这个链表的地址，用哨兵去遍历！！
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) {
            if(l1 == NULL) return l2;
            else return l1;
        }
        if(l1 == NULL && l2 == NULL) return NULL;
        //记得初始化一个ret结点，然后用哨兵ans去遍历！
        ListNode* ret = new ListNode();
        ListNode* ans = ret;
        
        while(l1 != NULL && l2 != NULL) { //记得是&&
            if(l1 -> val <= l2 -> val) {
                ans -> next = l1;
                l1 = l1 -> next;
            }
            else {
                ans -> next = l2;
                l2 = l2 -> next;
            }
            ans = ans -> next;
        }
        ans -> next = l1 == NULL? l2 : l1;
        return ret -> next;
    }
};
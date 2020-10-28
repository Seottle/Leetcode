#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 合并两个有序链表
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* pre = ans;
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val < l2 -> val) {
                pre -> next = l1;
                l1 = l1 -> next;
            }
            else{
                pre -> next = l2;
                l2 = l2 -> next;
            }  
            pre = pre -> next; 
        }
        if(l1 != NULL) {
        	pre -> next = l1;
		}
		else if(l2 != NULL){
			pre -> next = l2;
		}
        return ans -> next;
    }
};
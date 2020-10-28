#include <stdio.h>
#include <iostream>

using namespace std;

/**
@author: ZhengXiaoTao
@description: 
删除链表的倒数第N个节点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);//建立虚链表结点，初始值为空
        dummyHead -> next = head;
        
        ListNode* quick = dummyHead;
        ListNode* slow = dummyHead;

        n++; //初始位置是head之前
        while(n--) {
            quick = quick -> next;
        }
        while (quick != NULL)
        {
            slow = slow -> next;
            quick = quick -> next;
        }
        ListNode* deleteNode = slow -> next;
        slow -> next = deleteNode -> next;
        delete deleteNode;

        return dummyHead -> next;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description:2020/10/29 判断链表是否存在环
经典快慢指针！！！
慢指针走一步
快指针走两步
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr) 
            return false;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(slow != fast) {
            if(fast == nullptr || fast -> next == nullptr) {
                return false;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return true;
    }
};
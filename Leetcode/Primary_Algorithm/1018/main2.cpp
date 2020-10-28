#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 回文链表
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        set <int> hash;
        while(head != nullptr) {
            if(set.count(head -> val)) {
                return true;
            }
            set.insert(head -> val);
            head = head -> next;
        }
        return false;
    }
};

#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 删除链表中的节点
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
        void deleteNode(ListNode* node) {
            node -> val = node -> next -> val;
            node -> next = node -> next -> next;
        }
    };
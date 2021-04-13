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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy; // pre
        while(pre -> next != NULL && pre -> next -> next != NULL) {
            ListNode* node1 = pre -> next; // 1
            ListNode* node2 = pre -> next -> next; // 2
            pre -> next = node2; // pre 后接 2
            node1 -> next = node2 -> next; // 1 后接 3
            node2 -> next = node1; // 2 后接 1 此时变成 pre -> 2 -> 1 -> 3 -> ....
            pre = node1; // 更新pre 为 1
        }
        return dummy -> next;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;
        while(n--) {
            fast = fast -> next;
        }
        while(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* del = slow -> next;
        slow -> next = del -> next;
        delete(del);
        return dummy -> next;
    }
};
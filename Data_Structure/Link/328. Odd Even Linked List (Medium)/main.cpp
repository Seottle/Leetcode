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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* evenhead = head -> next;
        ListNode* odd = head;
        ListNode* even = evenhead;
        while(even != NULL && even -> next != NULL) {
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        odd -> next = NULL;
        even -> next = NULL;
        ListNode* o = odd;
        ListNode* e = even;
        bool k = true;
        while(head != NULL) {
            if(k) {
                o -> next = head;
                o = o -> next;
            }
            else {
                e -> next = head;
                e = e -> next;
            }
            head = head -> next;
            k = !k;
        } 
        o -> next = even -> next; // 奇数接偶的头
        e -> next = NULL;//偶的尾巴接空断链
        return odd -> next;
    }
};
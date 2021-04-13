class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2 != NULL) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ans -> next = NULL;
        while(!s1.empty() || !s2.empty() || carry > 0) {
            int a = s1.empty() ? 0 : s1.top();
            if(!s1.empty()) s1.pop();
            int b = s2.empty() ? 0 : s2.top();
            if(!s2.empty()) s2.pop();
            int sum = a + b + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            
            temp -> next = ans -> next;
            ans -> next = temp;
        }
        return ans -> next;
    }
};
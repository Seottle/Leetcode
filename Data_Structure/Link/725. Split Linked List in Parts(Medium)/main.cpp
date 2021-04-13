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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(root == NULL) return vector<ListNode*>(k, NULL);
        int length = 0;
        ListNode* tmp = root;
        while(tmp != NULL) {
            length++;
            tmp = tmp -> next;
        }
        int eachpart = length / k, mod = length % k;
        vector<ListNode*> ans(k, NULL);
        ListNode* pre = NULL; // 用来控制断链
        for(int i = 0; i < k; ++i) {
            ans[i] = root;
            int eachNumber = mod > 0 ? (eachpart +  1) : eachpart;
            for(int j = 0; j < eachNumber; ++j) {
                pre = root;
                root = root -> next;
            }
            pre -> next = NULL;//一部分完了,断链
            mod--;
        }
        return ans;
    }
};
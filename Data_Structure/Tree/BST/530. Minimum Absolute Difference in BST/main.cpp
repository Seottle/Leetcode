/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        stack<TreeNode*> S;
        TreeNode* cur = root;
        int pre = -1;
        int ret = INT_MAX;
        while(cur != NULL || !S.empty()) {
            while(cur != NULL) {
                S.push(cur);
                cur = cur -> left;
            }
            TreeNode* node = S.top();
            S.pop();
            if(pre == -1) {
                pre = node -> val;
            }
            else {
                ret = min(ret, abs(node -> val - pre));
                pre = node -> val;
            }
            cur = node -> right;
        }
        return ret;
    }
};
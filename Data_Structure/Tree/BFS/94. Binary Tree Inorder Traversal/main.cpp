/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> S;
        vector<int> ans;
        TreeNode* cur = root;
        while(cur != nullptr  || !S.empty()) {
            while(cur != nullptr) {
                S.push(cur);
                cur = cur -> left;
            }
            TreeNode* node = S.top();
            S.pop();
            ans.push_back(node -> val);
            cur = node -> right;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ret;
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty()) {
            TreeNode* node = S.top();
            S.pop();
            ret.push_back(node -> val);
            if(node -> left) S.push(node -> left);
            if(node -> right) S.push(node -> right);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
//递归的前序遍历
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        ans.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        dfs(root);
        return ans;
    }
};
//非递归的前序遍历
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ret;
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty()) {
            TreeNode* node = S.top();
            S.pop();
            ret.push_back(node -> val);
            if(node -> right) S.push(node -> right); //先右后左，保证左子树在前面！
            if(node -> left) S.push(node -> left);
        }
        return ret;
    }
};
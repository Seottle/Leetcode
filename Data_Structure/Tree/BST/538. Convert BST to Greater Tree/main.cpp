class Solution {
public:
    int sum = 0;
    void traval(TreeNode* root) {
        if(root == nullptr) return;
        traval(root -> right);
        sum += root -> val;
        root -> val = sum;
        traval(root -> left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        traval(root);
        return root;
    }
};
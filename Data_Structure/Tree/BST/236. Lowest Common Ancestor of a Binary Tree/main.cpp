class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        // 如果左子树为空，说明它们都在右子树一侧，说明最先递归到的right结点是最近公共祖先
        if(left == NULL) return right; 
        //同理
        if(right == NULL) return left;
        return root;
    }
};
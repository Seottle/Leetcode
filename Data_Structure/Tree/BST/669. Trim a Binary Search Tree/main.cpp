class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        //节点值比low还小时，直接把整个左边剪枝了，因为BST，左边都小于节点值的，直接去返回递归右边
        if(root -> val < low) return trimBST(root -> right, low, high);
        //同理
        if(root -> val > high) return trimBST(root -> left, low, high);
        root -> left = trimBST(root -> left, low, high);
        root -> right = trimBST(root -> right, low, high);
        return root;
    }
};
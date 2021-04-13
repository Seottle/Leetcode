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
    int recur(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftH = recur(root -> left);
        int rightH = recur(root -> right);
        if(leftH == 0 || rightH == 0) return leftH + rightH + 1;
        return min(leftH, rightH) + 1;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return recur(root);
    }
};
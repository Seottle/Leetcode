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
        if(root == NULL) return 0;
        int leftH = recur(root -> left);
        int rightH = recur(root -> right);
        if(abs(leftH - rightH) > 1 || leftH == -100 || rightH == -100) return -100;
        else return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int n = recur(root);
        if(n != -100) return true;
        else return false;
    }
};
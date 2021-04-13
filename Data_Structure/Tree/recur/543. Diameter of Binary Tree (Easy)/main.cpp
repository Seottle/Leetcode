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
    int ans = 0;
public:
    int recur(TreeNode* root) {
        if(root == NULL) return 0;
        int l = recur(root -> left);
        int r = recur(root -> right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        recur(root); 
        return ans;
    }
};
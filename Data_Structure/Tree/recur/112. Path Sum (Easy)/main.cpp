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
    bool ans = false;
    void recur(TreeNode* root, int targetSum) {
        if(root == nullptr) return;
        targetSum -= root -> val;
        if(root -> left == nullptr && root -> right == nullptr) {
            if(targetSum == 0) ans = true;
        }
        recur(root -> left, targetSum);
        recur(root -> right, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        recur(root, targetSum);
        return ans;
    }
};
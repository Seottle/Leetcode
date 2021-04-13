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
    int cnt = 0;
public:
    void recur(TreeNode* root, int sum) {
        if(root == nullptr) return;
        sum -= root -> val;
        if(sum == 0) {
            cnt++;
        }
        recur(root -> left, sum);
        recur(root -> right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        recur(root, sum);
        pathSum(root -> left, sum);
        pathSum(root -> right, sum);
        return cnt;
    }
};
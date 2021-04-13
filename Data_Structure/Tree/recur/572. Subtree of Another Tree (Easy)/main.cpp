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
    bool recur(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr || t == nullptr) return false;
        if(t -> val != s -> val) return false;
        return recur(s -> left, t -> left) && recur(s -> right, t -> right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
       if(s == nullptr) return false;
       //判断t是否是s的子树，所以s不一样要从根结点出发！
       return recur(s, t) || isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
};
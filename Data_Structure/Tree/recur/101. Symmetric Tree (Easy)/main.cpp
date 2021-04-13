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
    //方法：比较左右子树,需要两个指针pq控制两棵子树
    //镜像：p的左要等于q的右,p的右要等于q的左
    bool recur(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p -> val != q -> val) return false;
        return recur(p -> left, q -> right) && recur(p -> right, q -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return false;
        return recur(root, root);
    }
};  
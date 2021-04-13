//暴力
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        int ans1 = root -> val;
        if(root -> left != NULL) ans1 += rob(root -> left -> left) + rob(root -> left -> right);
        if(root -> right != NULL) ans1 += rob(root -> right -> left) + rob(root -> right -> right);
        int ans2 = rob(root -> left) + rob(root -> right);
        return max(ans1, ans2);
    }
};

//暴力 + 记忆化
//利用map做剪枝
class Solution {
public:
    map<TreeNode*, int> mymap;
public:
    int rob(TreeNode* root) {
        return recur(root);
    }
    int recur(TreeNode* root) {
        if(root == NULL) return 0;
        if(mymap[root] != 0) return mymap[root];
        int ans1 = root -> val;
        if(root -> left != NULL) ans1 += rob(root -> left -> left) + rob(root -> left -> right);
        if(root -> right != NULL) ans1 += rob(root -> right -> left) + rob(root -> right -> right);
        int ans2 = rob(root -> left) + rob(root -> right);
        int result = max(ans1, ans2);
        mymap[root] = result;
        return result;
    }
};
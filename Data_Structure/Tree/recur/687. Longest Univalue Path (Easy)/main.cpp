class Solution {
private:
    int ans = 0;
public:
    int recur(TreeNode* root) {
        if(root == nullptr) return 0;
        int Left = recur(root -> left);
        int Right = recur(root -> right);
        int arrowLeft = 0, arrowRight = 0;
        if(root -> left != nullptr && root -> val == root -> left -> val)
            arrowLeft += 1 + Left;
        if(root -> right != nullptr && root -> val == root -> right -> val)
            arrowRight += 1 + Right;
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        recur(root);
        return ans;
    }
};
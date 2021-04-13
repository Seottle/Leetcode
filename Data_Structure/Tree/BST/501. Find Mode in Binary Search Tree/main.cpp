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
    vector<int> ans;
    int cnt, mode = INT_MIN, base;
    void updata(int val) {
        if(val == base) {
            cnt++;
        }
        else {
            base = val;
            cnt = 1;
        }
        if(cnt == mode) {
            ans.push_back(base);
        }
        if(cnt > mode) {
            ans = vector<int> {base};
            mode = cnt;
        }
        return;
    }
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root -> left);
        updata(root -> val);
        inorder(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        inorder(root);
        return ans;
    }
};
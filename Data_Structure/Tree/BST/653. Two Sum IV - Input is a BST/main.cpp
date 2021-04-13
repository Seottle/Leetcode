//递归实现
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = ans.size() - 1;
        while(i < j) {
            if(ans[i] + ans[j] > k) {
                j--;
            }
            else if(ans[i] + ans[j] < k) {
                i++;
            }
            else break;
        }
        if(i >= j) return false;
        else return true;
    }
};
//非递归实现
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> S;
        TreeNode* cur = root;
        vector<int> ans;
        while(cur != nullptr || !S.empty()) {
            while(cur != nullptr) {
                S.push(cur);
                cur = cur -> left;
            }
            TreeNode* node = S.top();
            S.pop();
            ans.push_back(node -> val);
            cur = node -> right;
        } 
        int i = 0, j = ans.size() - 1;
        while(i < j) {
            if(ans[i] + ans[j] > k) {
                j--;
            }
            else if(ans[i] + ans[j] < k) {
                i++;
            }
            else break;
        }
        if(i >= j) return false;
        else return true;
    }
};
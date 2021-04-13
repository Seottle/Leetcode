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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = root -> val;
        while(!Q.empty()) {
            int size = Q.size();
            vector<int> temp;
            for(int i = 0; i < size; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                temp.push_back(node -> val);
                if(node -> left) {
                    Q.push(node -> left);
                }
                if(node -> right) {
                    Q.push(node -> right);
                }
            }
            ans = temp[0];
        }
        return ans;
    }
};

//流批 
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            root = Q.front();
            Q.pop();
            //先放右再放左
            if(root -> right)  Q.push(root -> right);
            if(root -> left) Q.push(root -> left);
        }
        return root -> val;
    }
};
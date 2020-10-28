#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 二叉树的层次遍历
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<vector<int>> ans;
        while(!Q.empty()) {
            int len = Q.size();
            vector<int> level;
            while(len--) {
                TreeNode* node = Q.front(); 
                Q.pop();
                if(node == nullptr) 
                    continue;
                level.push_back(node -> val);
                
                if(node -> left != NULL) Q.push(node -> left);
                if(node -> right != NULL) Q.push(node -> right);  
            }
            if(level.size() != 0)
                ans.push_back(level);
        }
        return ans;
    }
};
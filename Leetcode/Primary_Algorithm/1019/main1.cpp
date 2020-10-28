#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 求二叉树的高度
*/

//递归遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
//层次遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; 
        queue<TreeNode*> Q;  // 是queue不是Queue
        int ans = 0;
        Q.push(root);
        while(!Q.empty()) {
            int len = Q.size();
            while(len > 0) {
                TreeNode* temp = Q.front();
                Q.pop();
                len--;
                if(temp -> left) Q.push(temp -> left);
                if(temp -> right) Q.puth(temp -> right);
                
            }
            ans++;
        }
        return ans;
    }
};
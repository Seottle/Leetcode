#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

//非递归解法
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        stack<TreeNode*> S;
        TreeNode* cur = root;
        while(cur != nullptr || !S.empty()) {
            while(cur != nullptr) {
                S.push(cur);
                cur = cur -> left;
            }
            TreeNode* node = S.top();
            S.pop();
            k--;
            if(k == 0) {
                return node -> val;
            }
            cur = node -> right;
        }
        return 0;
    }
};
//中序遍历解法
class Solution {
public:
    int cnt = 0;
    int ans = 0;
    void inorder(TreeNode* root, int k) {
        if(root == nullptr) return;
        inorder(root -> left, k);
        cnt++;
        if(cnt == k) {
            ans = root -> val;
            return;
        }
        inorder(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
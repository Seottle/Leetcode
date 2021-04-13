#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

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
//递归写法
class Solution {

public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
//正常遍历
class Solution {

public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int cnt = 0;
        while(!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                if(node -> left != NULL) Q.push(node -> left);
                if(node -> right != NULL) Q.push(node -> right);
            }
            cnt++;
        }
        return cnt;
    }
};
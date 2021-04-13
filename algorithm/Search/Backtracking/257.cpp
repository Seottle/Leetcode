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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& ans, string tmp) {
        
        if(root -> left == nullptr && root -> right == nullptr)  {
            tmp += to_string(root -> val);
            ans.push_back(tmp);
            return;   
        }    
        tmp += to_string(root -> val);
        tmp = tmp + "->";
        //难道不是左右指针都为空的时候返回吗！！？？   错在了 我要先判断左右指针是否存在才能去dfs
        //如果本身左指针就不存在，我还去操作dfs，相当于拿一个空指针去dfs，那肯定是错的呀！！
        if(root -> left)dfs(root -> left, ans, tmp);  
        if(root -> right)dfs(root -> right, ans, tmp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        string tmp;
        dfs(root, ans, tmp);
        return ans;
    }
};
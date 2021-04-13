#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.9 不同的二叉搜索树 II
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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) return vector<TreeNode*> {};
        else return generate(1, n);
    }
    vector<TreeNode*> generate(int left, int right) {
        vector<TreeNode*> ans;
        if(left > right) {
            ans.push_back(nullptr);
            return ans;
        }
        for(int i = left; i <= right; ++i){
            vector<TreeNode*> leftNode = generate(left, i - 1);
            vector<TreeNode*> rightNode = generate(i + 1, right);

            for(int l = 0; l < leftNode.size(); ++l) {
                for(int r = 0; r < rightNode.size(); ++r) {
                    TreeNode* temp = new TreeNode(i);
                    temp -> left = leftNode[l];
                    temp -> right = rightNode[r];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
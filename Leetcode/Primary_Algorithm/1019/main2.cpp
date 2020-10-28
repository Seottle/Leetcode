#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 验证二叉搜索树
二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

故用中序遍历，若得到的是升序序列，则是二叉搜索树，如果其中当前结点的值小于前序结点，则不是。
*/


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long inorder = (long long)INT_MIN - 1;
        while(!s.empty() || root != nullptr) {
            while(root != nullptr) {
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            s.pop();
            if(root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
    }
};
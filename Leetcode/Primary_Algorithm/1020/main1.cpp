#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 对称二叉树
*/

class Solution {
public:
    
    bool Check(TreeNode* q, TreeNode* p) {
        if(q == nullptr && p == nullptr) {
            return true;
        }
        if(q == nullptr || p == nullptr) {
            return false;
        }
        return Check(q -> left, p -> right) && Check(p -> left, q -> right) && p -> val == q -> val;
    }
    bool isSymmetric(TreeNode* root) {
       return Check(root, root);
    }
};

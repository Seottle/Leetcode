//野蛮人解法
class Solution {
public:
    vector<int> temp;
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        temp.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root == 0) return 0;
        dfs(root);
        if(temp.size() == 1) return -1;
        sort(temp.begin(), temp.end());
        int cnt = 2;
        int ans = -1;
        for(int i = 0; i < temp.size(); ++i) {
            if(temp[i + 1] == temp[i]) continue;
            else {
                cnt--;
                if(cnt == 0) {
                    ans = temp[i];
                }
            }
        }
        return ans;
    }
};
//屌 直接解
//没有想到说 如果 左子树的值和根节点相同，去递归左子树的值 
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        if(root -> left == nullptr && root -> right == nullptr) return -1;
        int leftVal, rightVal;
        if(root -> left) leftVal = root -> left -> val;
        if(root -> right) rightVal = root -> right -> val;
        if(leftVal == root -> val) leftVal = findSecondMinimumValue(root -> left);
        if(rightVal == root -> val) rightVal = findSecondMinimumValue(root -> right);
        if(leftVal != -1 && rightVal != -1) return min(leftVal, rightVal);
        else if(leftVal == -1) return rightVal;
        else return leftVal; 
        
    }
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        vector<double> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int size = Q.size();
            double sum = 0;
            for(int i = 0; i < size; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                sum += node -> val;
                if(node -> left != nullptr) Q.push(node -> left);
                if(node -> right != nullptr) Q.push(node -> right);
            }
            ans.push_back(sum / size);
        }
        return ans;
    }
};
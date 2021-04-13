class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, -1);
        stack<int> S;
        for(int i = 0; i < len * 2 - 1; ++i) {
            while(!S.empty() && nums[i % len] > nums[S.top()]) {
                int t = S.top();
                S.pop();
                ans[t] = nums[i % len];
            }
            S.push(i % len);
        }
        return ans;
    }
};
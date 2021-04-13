// nlog 的时间复杂度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ret = 1;
        int cnt = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if((i + 1) != nums.size() && nums[i] == nums[i + 1]){
                continue;
            }
            if((i + 1) != nums.size() && nums[i] + 1 == nums[i + 1]){
                cnt++;
            }
            else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        return ret;
    }
};

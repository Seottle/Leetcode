class Solution {
public:
    //map的find方法是找到key值，map<key, value>
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()) {
                return {i, it -> second};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
//python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i, num in enumerate(nums): //记住这种操作
            if dic.get(target - num) is not None:
                return [i, dic.get(target - num)]
            dic[num] = i
        return []
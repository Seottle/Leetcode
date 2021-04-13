//超时   但是这个思维我也没得！
class Solution {
public:
    //找到一个x和x+1的序列，然后去找数组中等于x或等于x+1的值！
    int findLHS(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            bool flag = false; //标记是否存在一个[x, x+1]的序列
            for(int j = 0; j < nums.size(); ++j) {
                if(nums[i] == nums[j]) {
                    cnt++;
                }
                else if(nums[i] + 1 == nums[j]) {
                    cnt++;
                    flag = true;
                }
            }
            if(flag) {
                ret = max(ret, cnt);
            }
        }
        return ret;
    }
};
//哈希映射记录每个数出现的次数，然后再去找[x, x+1]这样的序列对，若有直接返回它们的value值的和
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mymap;
        for(int i = 0; i < nums.size(); ++i) {
            mymap[nums[i]]++;
        }
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(mymap.find(nums[i] + 1) != mymap.end()){
                ret = max(ret, mymap[nums[i]] + mymap[nums[i] + 1]);
            }
        }
        return ret;
    }
};
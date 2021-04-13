#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map;         //统计频次
        for(auto i:nums) map[i]++;         //auto 自动选择参数类型  , 
        //和c#的foreach(item i in nums) 效果一样，i遍历整个nums数组
        priority_queue<pair<int,int>> que;  
        for(auto m:map){                                //map默认按key值排序
            que.push(make_pair(m.second, m.first));     //优先队列（堆）按照value进行排序
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }

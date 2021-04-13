#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
@author: ZhengXiaoTao
@description:11/2 无重叠区间  参考公众号 labuladong
//区间调度题：按结束时间最早开始排序，先求出不重叠区间的个数，设定排序后的x_end为第一个不相交区间，所以初始值cnt为1，就是一开始选的x_end
c++ 记得把cmp写成静态的函数 
*/


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cnt = 1;

        int x_end = intervals[0][1];
        int length = intervals.size();
        for(int i = 1; i < length; ++i) {
            if(intervals[i][0] >= x_end) {
                cnt++;
                x_end = intervals[i][1];
            }
        }      
        return length - cnt;
    }
};
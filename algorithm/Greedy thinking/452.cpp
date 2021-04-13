#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020/11/3 用最少数量的箭引爆气球 
同区间调度题，思路依旧是找  结束最早!!!!!
*/


class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int cnt = 1;
        int x_end = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] > x_end) {
                cnt++;
                x_end = points[i][1];
            }
        }
        //此时的cnt是无交集的区间的最大个数
        return cnt;

    }
};
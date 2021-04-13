#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 11/2 分发饼干
贪心思想：最小的孩子最容易满足，从最小的开始找
*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                i++;
                j++;
                cnt++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};
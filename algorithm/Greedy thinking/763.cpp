#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.6 划分字母区间

此题的算法：用map映射记录每个字符出现的最远距离，依题意，每一段中的字母不重复，
故当i遍历到最远字符的位置时，截取为一段，此时可以保证这一段是最长的一段
*/


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        map<char, int> mymap;
        int len = S.size();
        for(int i = 0; i < len; ++i) {
            mymap[S[i]] = i;
        }
        int end = 0, start = 0;
        for(int i = 0; i < len; ++i) {
            end = max(end, mymap[S[i]]);
            if(end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
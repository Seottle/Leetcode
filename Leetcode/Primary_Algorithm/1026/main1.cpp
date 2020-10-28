#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 位1的个数
*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        string str = to_string(n);
        int cnt = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == 1) cnt++;
        }
        return cnt;
    }
};
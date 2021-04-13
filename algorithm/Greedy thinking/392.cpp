#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.5 判断子序列

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len = t.size();
        int j = 0;
        for(int i = 0; i < len; ++i) {
            if(t[i] == s[j]) {
                j++;
            }
        }
        if(j == s.size()) return true;
        else return false;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description:leetcode 字符串中的第一个唯一字符 
*/


class Solution {
public:
    int firstUniqChar(string s) {
        int hash[10010];
        for(int i = 0; i < 10010; ++i) {
            hash[i] = 0;
        }
        for(int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(hash[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 有效的字母异位
理解错题一了，我以为是左右以为，原来是整个字母里面的异位置
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.size(); ++i) {
        	if(s[i] != t[i]) return false;
		}
		return true;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 最长回文串

方法：统计串中字符的个数，可以用来构成回文串的一定是出现偶数个的字符，他们可以组成的长度是 
（cnt / 2) * 2。 即 若cnt = 5 可以提供出4的长度。
找完所有的偶之后，判断此时的回文串长度和实际串的长度，若小于，说明一定有一个字符是单独出现的，最长回文串能再加1
*/


class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        for(int i = 0; i < s.size(); ++i) {
            mymap[s[i]]++;
        }
        int ans = 0;
        map<char, int> :: iterator it;
        for(it = mymap.begin(); it != mymap.end(); ++it) {
            ans += (it -> second / 2) * 2;
        }
        if(ans < s.size()) ans++;
        return ans;
    }
};
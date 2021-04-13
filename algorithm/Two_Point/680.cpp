#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 验证回文字符串 Ⅱ
s.erase(position, count);删除s中从下标为position位置的count个元素
*/


class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;
        int flag = 1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j -1);
            }
        }
        if(i >= j) return true;
        else return false;
    }
};
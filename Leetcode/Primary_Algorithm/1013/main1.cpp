#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 验证回文串
*/


class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int len = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= 'a' && s[i] <= 'z')) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
                temp[len++] = s[i];
            }
        }
        int i = 0, j = temp.size() - 1;    
        while(i < j) {
            if(temp[i] == temp[j]) {
                i++;
                j--;
            }
        }
        if(i > j) return true;
        else return false;
    }
};
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
@author: ZhengXiaoTao
@description:  2020/10/29 通过删除字母匹配到字典里最长单词
1.可以通过双指针的方法，i遍历整个原字符串，j遍历字串，若str[i] == target[j] j++ ; 最后如果j == target.size() 说明 target是字串
    逐个拿判断原字符串去和数组中的字符串比较，如果数组的字符串里的字母，原字符串都有，则说明数组中的字符串是原字符串的子串！

*/


class Solution {
public:
    bool IsSubStr(string str, string target) {
        //双指针判断target是否为str的子串
        int i, j = 0; 
        for(i = 0; i < str.size(); ++i) {
            if(str[i] == target[j]) {
                j++;
            }
        }
        if(j == target.size()) return true;
        else return false;
    }

    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for(int i = 0; i < d.size(); ++i) {
            int SubStrLength = d[i].size(); // 数组中字符串的长度
            int AnsLength = ans.size(); // 获得的ans的长度
            //如果当前得到的ans最长字串的长度已经大于 数组中字符串的长度， 或者相等，但是字母序大于ans的，则跳过
            if(AnsLength > SubStrLength || (AnsLength == SubStrLength && d[i] > ans)) {
                continue;
            }
            if(IsSubStr(s, d[i])) {
                ans = d[i];
            }
        }      
        return ans;
    }
};
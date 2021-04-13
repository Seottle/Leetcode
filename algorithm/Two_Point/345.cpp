#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 反转字符串的元音字母
这题可以往快速排序的思路上想，经典双指针
我犯了三个严重错误
第一是把里面的while循环写成if了，if也行，但是要continue继续执行，
第二是里面的while条件都是i < j （我一开始写成 i < size ，导致了换了两次最后输出原串) 
第三每次找到元音字母交换后都要i++和j--，否则循环无法继续执行啊啊啊啊啊啊啊啊！
*/


class Solution {
public:
    string reverseVowels(string s) {
        
        int i = 0, j = s.size() - 1;
        while(i < j) {
            char ch;
            while(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && (i < j)) {
                i++;
            }
            while(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U'&& (i < j)) {
                j--;
            }
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
            
        }
        return s;
    }
};
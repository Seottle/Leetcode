#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.7寻找比目标字母大的最小字母
*/


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size() - 1;
        if(target >= letters[len] || target < letters[0]) return letters[0];
        
        int left = 0, right = len;
        char ans;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(letters[mid] > target) {
                ans = letters[mid];
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
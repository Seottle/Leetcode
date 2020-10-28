#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 第一个错误的版本
*/

class Solution {
public:
    int firstBadVersion(int n) {
        return Binary(1, n);
    }
    int Binary(int left, int right) {
        int mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(isBadVersion(mid)) {
               right = mid;
            } 
            else left = mid + 1;
        }
        return left;
    }
};
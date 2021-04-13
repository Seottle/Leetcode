#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.4 种植花朵
*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int len = flowerbed.size();
        for(int i = 0; i < len; ++i) {
           // 000 100 001 都是可以的
           if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0) ) {
              count++;
              flowerbed[i] = 1; 
           }
        }
        if(n <= count) return true;
        else return false;
    }
};
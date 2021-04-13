#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020/11/7 求平方根
二分法求解：一个数的开平方，肯定在1-他本身之间，所以可以用二分法查找
由于开根号是取下界，所以把判断条件要放在 mid*mid <= x 上，记录ans = mid！
*/


class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }
        int left = 1, right = x;
        int ans;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 平方数之和
相比 167的 两数之和
也是用双指针的办法，j只需要判断到 sqrt(target) 之下就可以了
注意此题会整型溢出，选用long long 即可
还有就是会出现 a^2 + a^2  = target的情况，所以循环条件改为  i <= j 
*/


class Solution {
public:
    bool judgeSquareSum(int c) {
        bool flag = false;
        long long i = 0, j = (long long)sqrt(c);
        while(i <= j) {
            long long  temp = i * i + j * j;
            if(temp > c) j--;
            else if(temp < c) i++;
            else {
                flag = true;
                break;
            }
        }
        return flag;
    }
};
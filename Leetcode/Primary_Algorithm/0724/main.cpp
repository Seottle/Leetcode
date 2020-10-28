#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size() - 1;
        for(; digits[len] == 9 && len > 0; --len) {
            digits[len] = 0;
        }
        if(len == 0 && digits[len] == 9) {
            digits[0] = 1;
            for(int i = 1; i < len; ++i) {
                digits[i] = 0;
            }
            digits.push_back(0);
        }
        else {
            digits[len] += 1; 
        }
        return digits;
    }    
};

int main() {

    cout<<endl;
    system("pause");
    return 0;
}
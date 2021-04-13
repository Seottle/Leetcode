#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 9  为运算表达式设计优先级
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //分治法
        vector<int> ans;
        int len = input.size();
        for(int i = 0; i < len; ++i) {
            char c = input[i];
            vector<int> left;
            if(c == '+' || c == '-' || c == '*') {  //遇到运算符时，开始分治找左右两边的数字
                vector<int> left = diffWaysToCompute(input.substr(0, i));  //递归的找到
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(int l = 0; l < left.size(); ++l) {
                    for(int r = 0; r < right.size(); ++r) {
                        switch(c) {
                            case '+':
                                ans.push_back(left[l] + right[r]);
                                break;
                            case '-':
                                ans.push_back(left[l] - right[r]);
                                break;
                            case '*':
                                ans.push_back(left[l] * right[r]);
                                break;
                        }
                    }
                }
            }
        }
        if(ans.empty()) {
            ans.push_back(stoi(input));
        }
        return ans;
    }
};

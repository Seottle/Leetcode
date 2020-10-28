#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 汉明距离
*/
/* 思路：转为二进制 再去判断每一位， 下面代码有错误，对栈的不理解导致
class Solution {
public:
    int hammingDistance(int x, int y) {
        stack<int> X = to_binary(x);
        stack<int> Y = to_binary(y);
        int cnt = 0;
        while(!X.empty()) {
            int a = X.top();    
            X.pop();
            int b = Y.top();
            Y.pop();
            if(a & b) cnt++;
        }
        return cnt;
    }
    stack<int> to_binary(int n) {
        stack<int> ans;
        while(n != 0) {
            ans.push(n % 2);
            n /= 2;
        }
        for(int i = 0; i < 32; ++i) {
            int temp = ans.top();ans.pop();
            if(temp != 1) ans.push(0);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x != 0 && y != 0) {
            int a = x % 2;
            int b = y % 2;
            if(a != b) cnt++;
            x = x / 2;
            y = y / 2;
        }
        while(x != 0) {
            if(x & 1) cnt++;
            x >>= 1;
        }
        while(y != 0) {
            if(y & 1) cnt++;
            y >>= 1;
        }
        return cnt;
    }
};
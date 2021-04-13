#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 17 组合总和
遇到这种求和的题，最好是用减法！！  递归调用到值为0的时候就是符合条件的时候
*/


class Solution {
public:
    void dfs(int n, int k, int index, vector<int> temp, int& max) {
        if(n == 0) {
            int sum = 1;
            for(int i = 0; i < temp.size(); ++i) {
            	if(temp[i] != 0) {
            		sum = sum * temp[i];
            	
				} 
			}
            if(sum > max) {
                max = sum;
            }
            return;
        }
        for(int i = index; i < k; ++i) {
            if(i <= n) {
                temp.push_back(i);
                dfs(n - i, k, index + 1, temp, max);
                temp.pop_back();
            }
        }
        return ;
    }
    int cuttingRope(int n) {
        int max = 0;
        if(n == 2) return 1;
        vector<int> temp(n);
        dfs(n, n, 1, temp, max);
        return max;
    }
};
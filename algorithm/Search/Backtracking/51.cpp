#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 20 N皇后

用find这个函数，去找这个序列中的i元素，如果序列中所找的这个元素不存在，就会返回end()。
*/


class Solution {
public:
    set<int> colume;
    set<int> dig1;
    set<int> dig2;
    
    void dfs(vector<vector<string>>& ans, int n, int index, vector<int> q) {
        if(index == n) {
            vector<string> temp; // 定义一个string向量组
            for(int i = 0; i < n; ++i) {
                string str(n, '.'); 
                str[q[i]] = 'Q';
                temp.push_back(str); //放入每个str
            }
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(colume.find(i) != colume.end()){ //找不到i 就会返回colume.end()
                continue;
            }
            int dignum1 = index - i;
            if(dig1.find(dignum1) != dig1.end()){ // 左斜对角线的规律是  在左斜对角上，行-列的值都相等
                continue;
            }
            int dignum2 = index + i;
            if(dig2.find(dignum2) != dig2.end()) { //右斜对角线的规律是 在右斜对角上，行+列的值都相等
                continue;
            }
            q[index] = i; //记录可以放Q的位置
            colume.insert(i);
            dig1.insert(dignum1);
            dig2.insert(dignum2);
            dfs(ans, n, index + 1, q);
            //q[index] = -1;
            colume.erase(i);
            dig1.erase(dignum1);
            dig2.erase(dignum2);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> q(n, -1); // 用来标记是否能放Q的
        dfs(ans, n, 0, q);
        return ans;
    }
};
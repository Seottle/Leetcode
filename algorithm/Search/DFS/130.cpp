#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.12
我一开始的想法是，用标记数组标记出矩阵中所有的圆，然后判断那些圆有没有在边界的，边界的看有没有和内部的相连，有就不变，很僵硬!!!

此题解法：确实是考虑边界问题，可以只判断边界的圆，然后对边界的圆，走上下左右四个方向，有就把它们都变成"A"也就是标记
最后，遍历整个矩阵，如果有A的，说明和边界连着了，就变成圆，如果还有圆，说明是内部的圆，变成X

记得对于二维vector要判断一维和二维长度是否为0才去做题 若是 直接return {}
*/


class Solution {
public:
    int n, m;
    //定义四个方向
    vector<vector<int>> direc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& visit) {
        if(visit[i][j] == 1) return;
        visit[i][j] = 1;
        
        //遍历四个方向
        for(vector<int> d : direc) {
            int nexti = i + d[0];
            int nextj = j + d[1];
            if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= m || matrix[i][j] > matrix[nexti][nextj]) 
                continue;
            dfs(matrix, nexti, nextj, visit);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) 
            return {};
        vector<vector<int>> ans;
        n = matrix.size();
        m = matrix[0].size();
        //双向DFS，定义两个标记数组
        vector<vector<int>> CanreachP(n, vector<int>(m, 0)); //标记大西洋
        vector<vector<int>> CanreachA(n, vector<int>(m, 0)); //标记太平洋

        for(int i = 0; i < n; ++i) {
            dfs(matrix, i, 0, CanreachP);
            dfs(matrix, i, m - 1, CanreachA);
        }

        for(int i = 0; i < m; ++i) {
            dfs(matrix, 0, i, CanreachP);
            dfs(matrix, n - 1, i, CanreachA);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(CanreachP[i][j] == 1 && CanreachA[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.13 太平洋大西洋水流问题
本题亮点：双向DFS
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
        vector<vector<int>> ans;
        if(matrix.size() == 0 || matrix[0].size() == 0) return; //又忘了这步防止直接溢出的操作
        
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
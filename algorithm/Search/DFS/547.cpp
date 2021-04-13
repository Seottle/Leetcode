#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.12 朋友圈

*/
//bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visit(M.size(), 0);
        queue<int> Q;
        int ans = 0;
        for(int i = 0; i < M.size(); ++i) {
            if(visit[i] == 0) {
                Q.push(i);
                while(!Q.empty()) {
                    int q = Q.front();
                    Q.pop();
                    for(int j = 0; j < M.size(); ++j) {
                        if(M[q][j] == 1 && visit[j] == 0) {
                            visit[j] = 1;
                            Q.push(j);
                        }
                    }
                }
                ans++;
            }
        }
    }
    return ans;
};

//dfs找无向图的连通分量的个数
class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<int>& visit, int points) { 
         visit[points] = 1;
         int n = M.size();
         for(int j = 0; j < n; ++j) {
             if(M[points][j] == 1 && visit[j] == 0) {
                 dfs(M, visit, j);
             }
         }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> visit(n, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(visit[i] == 0) {
                dfs(m, visit, i);
                ans++;
            }
        }
        return ans;
    }
};
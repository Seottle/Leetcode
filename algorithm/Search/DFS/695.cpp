#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 202.11.11

卡住的想法是：对于每个点，都进行一次BFS或DFS
*/

#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.11岛屿的最大面积
*/

//网格类 DFS 的写法
//当有可行解时，递归调用本身，直到null，
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0 || col == 0) return 0;
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) {
                    //DFS
                    int tmp = dfs(grid, i, j);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};

//BFS
class Solution {
public:
    struct Node
    {
        int r;
        int c;
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) { //遇到1时，进行遍历 
                    queue<Node> Q;
                    Q.push({i, j});
                    grid[i][j] = 0;
                    int level = 0;
                    while(!Q.empty()) {
                        Node node = Q.front();
                        int r = node.r;
                        int c = node.c;
                        Q.pop();
                        level++;
                        vector<Node> dic = {{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};//上下左右四个方向
                        for(int d = 0; d < dic.size(); ++d) {
                            if(dic[d].r < 0 || dic[d].r >= row || dic[d].c < 0 || dic[d].c >= col || grid[dic[d].r][dic[d].c] == 0) continue;
                            grid[dic[d].r][dic[d].c] = 0;
                            Q.push(dic[d]);
                        }
                    }
                    ans = max(ans, level);
                }
            }
        }
        return ans;
    }
};
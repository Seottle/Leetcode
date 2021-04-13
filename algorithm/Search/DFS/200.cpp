#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.11 岛屿数量

网格类经典DFS解法
*/

//DFS
class Solution {
public:
    int dfs(vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') return 0;
        grid[row][col] = '0';
        return 1 + dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0 || col == 0) return 0;
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    //DFS
                    int tmp = dfs(grid, i, j);
                    if(tmp > 0) ans++;
                }
            }
        }
        return ans;
    }
};

//BFS
class Solution {
public:
    struct Node {
        int row;
        int col;
    };
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    queue<Node> Q;
                    Q.push({i, j});
                    //int level = 0;
                    while(!Q.empty()) {
                        //level++;
                        Node node = Q.front();
                        Q.pop();
                        int x = node.row;
                        int y = node.col;
                        vector<Node> dic = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
                        for(int d = 0; d < dic.size(); ++d) {
                            if(dic[d].row < 0 || dic[d].row >= row || dic[d].col < 0 || dic[d].col >= col || grid[dic[d].row][dic[d].col] == '0') continue;
                            grid[dic[d].row][dic[d].col] = '0';
                            Q.push(dic[d]);
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
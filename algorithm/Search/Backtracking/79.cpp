#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 16  单词搜索

*/


class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool dfs(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visit, int index,string word)    {
        if(index == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visit[row][col] == 1 || board[row][col] != word[index]) return false;
        
        visit[row][col] = 1;
        for(vector<int> d : dir) {
            int nextrow = row + d[0];
            int nextcol = col + d[1];
            if(dfs(board, nextrow, nextcol, visit, index + 1, word)) //跟顺序有关
                return true;
        }
        visit[row][col] = 0;  // 这一步是关键啊，如果上下左右都不能找到点，就取消访问这个点，便于以后访问
                             // 我当时想到的处理如果上下左右找不到点，就重新resize visit数组 太sb了
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0 || word.size() == 0) return false;
        int row = board.size();
        int col = board[0].size();
        int index = 0;
        vector<vector<int>> visit(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(dfs(board, i, j, visit, index, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
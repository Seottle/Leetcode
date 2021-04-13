#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description:  2020 11 20 解数独  hard
*/

class Solution {
public:
    bool line[9][9];
    bool colume[9][9];
    bool block[3][3][9];  // 9 * 9 的数独有  9 个宫格  !
    vector<pair<int, int>> temp; // 存放待存放数
    bool valid;
    void dfs(vector<vector<char>>& board, int index) {
        if(index == temp.size()) {  //能成功走完待存放数组的位置，说明是可以放的
            valid = true;
            return;
        }
        auto [r, c] = temp[index]; // temp[0] 存的是 pair对！记住这一点， 然后可以用auto [r, c] 取出这一对，r即指向队中的i ，同理c 
        for(int i = 0; i < 9 && valid == false; ++i) {  // 是从 0 - 9的数字
            if(line[r][i] == false && colume[c][i] == false && block[r / 3][c / 3][i] == false) {
                line[r][i] = true;                    
                colume[c][i] = true;
                block[r / 3][c / 3][i] = true;

                board[r][c] = i + '0' + 1;
                dfs(board, index + 1);      // 这里index用来指向空格
                        
                line[r][i] = false;
                colume[c][i] = false;
                block[r / 3][c / 3][i] = false;
            
                }
        }
       
    }

    void solveSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        memset(line, false, sizeof(line));
        memset(colume, false, sizeof(colume)); 
        memset(block, false, sizeof(block));

        bool valid = false;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == '.') {
                    temp.push_back({i, j});
                }
                else {
                    int x = board[i][j] - '0' - 1;
                    line[i][x] = true;
                    colume[j][x] = true;
                    block[i / 3][j / 3][x] = true;
                }
            }
        }         
        dfs(board, 0);
    }
};
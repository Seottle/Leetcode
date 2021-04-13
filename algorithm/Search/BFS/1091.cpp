#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020.11.10 BFS

BFS做题模板：

定义一个队列
定义一个备忘录 

判断特殊直接结束条件， 满足直接返回

把初始点放入队列
备忘录记录访问初始点

while(队列不为空) {
    记录此时队列的元素个数
    for(队列的元素个数) {
        取出队列的元素  front pop

        剔除不符合题目要求条件的点

        把符合条件的点加入队列
        备忘录记录
    }
}
*/


class Solution {
public:
    struct Node
    {
        int row;
        int col;
        Node(int row_, int col_) {
            row = row_;
            col = col_;
        }
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<Node> Q;
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1) return -1;

        vector<vector<int>> memo(row, vector<int>(col, 0)); // row个 vector<int> 其中 vector<int> 为 col 个 0
        Q.push(Node(0, 0));
        //Q.push({0, 0});
        memo[0][0] = 1;
        int ans = 0;
        while(!Q.empty()) {
            int size = Q.size();
            ans++;
            for(int i = 0; i < size; ++i) {
                Node node = Q.front();
                int r = node.row;
                int c = node.col;
                Q.pop();
                if(r == (row - 1) && c == (col - 1))
                    return ans;
                //下一个结点所以可能情况
                vector<Node> way = {{r - 1, c - 1}, {r - 1, c}, {r - 1, c + 1}, {r, c - 1}, {r , c + 1}, 
                                    {r + 1, c - 1}, {r + 1, c}, {r + 1, c + 1}};
                for(int j = 0; j < way.size(); ++j) {
                    
                    //判断有没有越界
                    if(way[j].row < 0 || way[j].row >= row || way[j].col < 0 || way[j].col >= col) {
                        continue;
                    }
                    //判断有没有在备忘录里出现
                    if(memo[way[j].row][way[j].col] == 1)
                        continue;
                    //判断这个位置是不是被阻塞
                    if(grid[way[j].row][way[j].col] == 1)
                        continue;

                    memo[way[j].row][way[j].col] = 1;
                    Q.push(way[j]);
                }
               
            }
            
        }
        return -1;
    }
};
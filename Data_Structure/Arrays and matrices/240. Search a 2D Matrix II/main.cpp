#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() * matrix[0].size() == 0) return false;
        int row = matrix.size() - 1, col = 0;
        while(row >= 0 && col < matrix[0].size()) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] > target) {
                row--;
            }
            else {
                col++;
            }
        }
        return false;
    }
};
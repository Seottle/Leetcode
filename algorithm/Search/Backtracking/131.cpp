#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 19 分割回文串

报错  heap overflow 
解决方法 看数组是否越界！

*/


class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    void dfs(vector<vector<string>>& ans, string s, vector<string> temp, int index) { 
        if(index == s.size()) {  // 当index 增长到 s的长度时， 说明成功找到一组，加入ans中 
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(huiwen(s, index, i)) {
                string str = s.substr(index, i - index + 1);
                temp.push_back(str);
            }
            else continue;
            dfs(ans, s, temp, i + 1); //从i + 1 不是从index + 1 嗷!
            temp.pop_back();
        }
    }
    
    bool huiwen(string s, int start, int end) {
        for(int i = start, j = end; i < end && j >= 0; ++i, --j) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        
        if(s.size() == 0) return ans;
        

        dfs(ans, s, temp, 0);
        return ans;
    }
};

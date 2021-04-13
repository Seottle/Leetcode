#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
@author: ZhengXiaoTao
@description:2020 11 15 数字键盘组合            （2020 11 14 日 和最好的朋友有个奇妙的夜晚）
Backtracking（回溯）属于 DFS。

普通 DFS 主要用在 可达性问题 ，这种问题只需要执行到特点的位置然后返回即可。
而 Backtracking 主要用于求解 排列组合 问题，例如有 { 'a','b','c' } 三个字符，求解所有由这三个字符排列得到的字符串，这种问题在执行到特定的位置返回之后还会继续执行求解过程。
因为 Backtracking 不是立即返回，而要继续求解，因此在程序实现时，需要注意对元素的标记问题：

在访问一个新元素进入新的递归调用时，需要将新元素标记为已经访问，这样才能在继续递归调用时不用重复访问该元素；
但是在递归返回时，需要将元素标记为未访问，因为只需要保证在一个递归链中不同时访问一个元素，可以访问已经访问过但是不在当前递归链中的元素。
*/


class Solution {
public:
    void dfs(vector<string>& ans, string tmp,int index, string digits, map<char, string> phone) {
        if(tmp.size() == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        string str = phone[digits[index]];
        for(int i = 0; i < str.size(); ++i) { // i从0开始
            tmp.push_back(str[i]);
            dfs(ans, tmp, index + 1, digits, phone);
            tmp.pop_back();   //关键
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        if(digits.size() == 0) return ans;
        map<char, string> phone = {{'0', ""}, {'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        dfs(ans, temp, 0, digits, phone);
        return ans;
    }
};
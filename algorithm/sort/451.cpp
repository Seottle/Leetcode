#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 11/1 根据字符出现频率排序
通过这题和347题，要学会知识点
1.map 和 pair 的配合使用，常常计算需要两个元素的数据表示。
2.for(auto i : nums) 和 C#里的foreach很像， 快速遍历数组，不会也行，问题不大
3.优先队列priority_queue<type> Q;   排好序的队列 超级好用
*/


class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mymap;
        for(auto i : s) {
            mymap[i]++;
        }
        priority_queue<pair<int, char>> Q;  //map默认按key排序，想改成按value排序，定义一个优先队列的pair<value, key> 致命错误
        for(auto i : mymap) {
            Q.push(make_pair(i.second, i.first));
        }
        string ans;
        while(!Q.empty()) {
            auto temp = Q.top();
            Q.pop();
            //append函数是向string的后面追加字符或字符串。
            ans.append(temp.first, temp.second);
        }
        return ans;
    }
};


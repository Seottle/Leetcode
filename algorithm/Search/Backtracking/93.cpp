#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020 11 15 复原IP地址

    一个合法的 IP 地址必须为四段，即 x.x.x.x 的格式。
    所以可以用一个 segcnt 表示当前 IP 的段数，segcnt == 4 为结束条件。
    每当 segcnt == 4 时，判断已经匹配的字符串长度是否和 s 的长度相等，如果相等则是正确答案。
    第一个字符如果是 0，说明第一段只能是0。
    如果 3 个字符串拼在一起大于 255，则必须放弃这段字符串。

*/


class Solution {
public:
    vector<int> seg;
    vector<string> ans;
    void dfs(int segcnt, string s, int strStart) {
        if(segcnt == 4) {
            if(strStart == s.size()) {
                string tmp;
                for(int i = 0; i < 4; ++i) {  
                    tmp = tmp + to_string(seg[i]);  // 不能temp += (seg[i] + '0); 因为seg[i] -'0'得到的是整型!!
                    if(i < 3) {
                        tmp = tmp + ".";
                    }
                }
                ans.push_back(tmp);
            }
            return;
        }

        if(strStart == s.size()) return;//没到四段就遍历完整个s了，直接返回
        
        if(s[strStart] == '0') {  // 如果存在前导零，前导零肯定单独是一段！
            seg[segcnt] = 0;
            dfs(segcnt + 1, s, strStart + 1);
        }
        int temp = 0;
        for(int i  = strStart; i < s.size(); ++i) { //i从strstart开始
            temp = temp * 10 + (s[i] - '0'); 
            if(temp > 0 && temp <= 255) { //每满足条件就算一段
                seg[segcnt] = temp;
                dfs(segcnt + 1, s, i + 1);
            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        seg.resize(4); // 必须初始化seg 因为你有判断vector内存的大小的操作
        dfs(0, s, 0);
        return ans;
    }
};
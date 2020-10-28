#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 有效的括号
*/
class Solution {
    public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.size()==0) return true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(stk.empty()) return false;
                else if(stk.top()=='(')
                {
                    stk.pop();
                }
                else return false;
            }
            else if(s[i]==']')
            {
                if(stk.empty()) return false;
                else if(stk.top()=='[')
                {
                    stk.pop();
                }
                else return false;
            }
            else if(s[i]=='}')
            {
                if(stk.empty()) return false;
                else if(stk.top()=='{')
                {
                    stk.pop();
                }
                else return false;
            }

        }
        if(stk.empty()) return true;
        else return false;
    }
};



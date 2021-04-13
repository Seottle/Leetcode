#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 2020/11/3 
*/


class Solution {
public:
    static bool mycompare(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])return a[0]>b[0];
        else return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),mycompare);
        for(int i=0;i<people.size();i++)
        {
            if(people[i][1] != i){//和插入排序类似，每次前i-1的个数的顺序已经排好
            //把people[i]放到people[i][1]对应的下标位置上
                 vector<int> temp = people[i]; // 相当于拿了一块出来
                int target = people[i][1];
                int j = i;
                while(j > target){
                    people[j] = people[j - 1];
                    j--;
                } 
                people[target] = temp;

            }
        }
        return people;

    }
};
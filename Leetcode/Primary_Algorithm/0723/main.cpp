#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 给定两个数组，编写一个函数来计算它们的交集。
示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> myMap;
        for(int i = 0; i < nums1.size(); ++i) {
            myMap[nums1[i]]++;
        }
        vector <int> ans;
        for(int i = 0; i < nums2.size(); ++i) {
            if(myMap[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                myMap[nums2[i]]--;
            }
        }
        return ans;
    }
};
int main() {
    
    cout<<endl;
    system("pause");
    return 0;
}
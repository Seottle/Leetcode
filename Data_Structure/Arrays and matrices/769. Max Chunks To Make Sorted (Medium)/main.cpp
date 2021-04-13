#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/

//当所处位置的值最大且正好是下标时，表示此时前面的值都比他小，可以分块
//否则说明在其之后一定有比他小的数字，那就不合理了
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int pos = arr[0];
        for(int i = 0; i < arr.size(); ++i) {
            pos = max(arr[i], pos);
            if(pos == i) cnt++;
        }
        return cnt;
    }
};
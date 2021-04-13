#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/


class Solution:
    def isPalindrome(self, x: int) -> bool:
        lst = list(str(x))
        start = 0
        end = len(lst) - 1
        while start < end :
            if lst[start] != lst[end]:
                return False
            start += 1
            end -= 1
        if start >= end:
            return True
        else :
            return False
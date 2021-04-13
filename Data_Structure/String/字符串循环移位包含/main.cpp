#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 

s1 = AABCD, s2 = CDAA
Return : true
给定两个字符串 s1 和 s2，要求判定 s2 是否能够被 s1 做循环移位得到的字符串包含。

s1 进行循环移位的结果是 s1s1 的子字符串，因此只要判断 s2 是否是 s1s1 的子字符串即可。
*/


#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1,str2;
	while(cin >> str1 >> str2) {
		string temp = str1 + str1;
		if(temp.find(str2) != -1) cout << "True" << endl;
		else cout << "False" << endl;
	}
	return 0;
}

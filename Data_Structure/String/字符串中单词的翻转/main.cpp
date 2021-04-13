#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
s = "I am a student"
Return "student a am I"

先翻转每个单词，然后反转整个字符串
*/

void swap(string& str, int i, int j) {
	while(i < j) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int main() {
	string str;
	
	while(getline(cin, str)) {
		int start = 0, end;
		for(int i = 0; i < str.size(); ++i) {
			if(str[i] == ' ') {
				end = i - 1;
				swap(str, start, end);
				start = i + 1;
			}
		}
		swap(str, start, str.size() - 1);
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	
    return 0;
}
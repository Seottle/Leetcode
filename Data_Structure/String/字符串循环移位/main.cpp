#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
s = "abcd123" k = 3
Return "123abcd"
*/


int main() {
	string str1;
	int k;
	while(cin >> str1 >> k) {
		string temp;
		for(int i = 0; i < str1.size(); ++i) {
			temp[i] = str1[(i + k + 1) % str1.size()];
		}	
		for(int i = 0; i < str1.size(); ++i) {
			str1[i] = temp[i];
		}
		cout << str1 << endl;
	}
    cout<<endl;
    return 0;
}
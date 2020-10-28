#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <float.h>
using namespace std;
//LeetCode 整数反转
int reverse(int x) {
		int n, ans = 0;
		while(x != 0) {
			if(ans > 214748364 || ans < -214748364) return 0;
			n = x % 10;
			ans = ans * 10 + n;
			x = x / 10;
		}
		return ans;
    }
int main() {
	int n;
	while(cin >> n) {
		cout << reverse(n) << endl;
	}
	return 0;
} 
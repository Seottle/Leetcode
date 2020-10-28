#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
using namespace std;


int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') {
            i++;
        }
        long long ans = 0;
        if(s[i] == '-') {
            i++;
            if(s[i] >= '0' && s[i] <= '9') {
                while(s[i] >= '0' && s[i] <= '9') {
                	if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && s[i] -'0' > 8)) {
                        ans = -1 * 2147483648;
                        return ans;
                	}
                    ans = ans * 10 + (-1 * (s[i] - '0'));
					i++;
                }
                if(ans < INT_MIN) ans = INT_MIN;
                return ans;
            }
            else return 0;
        }
        else if(s[i] == '+') {
            i++;
            if(s[i] >= '0' && s[i] <= '9') {
                while(s[i] >= '0' && s[i] <= '9') {
                    
                    if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] -'0' > 7)) {
                   		ans = 2147483647;
                        return ans;
                    }
                    ans = ans * 10 + (s[i] - '0');
                    i++;
                }
                if(ans > INT_MAX) {
                        ans = INT_MAX;                       
                        return ans;
                    }
                return ans;
            }
            else return 0;
        }
        else if(s[i] >= '0' && s[i] <= '9') {
            for(;s[i] >= '0' && s[i] <= '9';++i) {
					if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] -'0' > 7)) {
						ans = 2147483647;
						return ans;	
					}
                    ans = ans * 10 + (s[i] - '0');
					
                }
                if(ans > INT_MAX) ans = 2147483647;
                return ans;
        }
        else return 0;
    }


   


int main() {
	string str;
	while(getline(cin,str)) {
		cout << myAtoi(str) << endl;
	}
	
	return 0;
} 
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


string countAndSay(int n) {
        if(n == 1) return "1";
        else if(n == 2) return "11";
        string temp = "11";
        string ans = "";
        n -= 2;
        while(n--) {
			cout << temp;
            int count = 1;
            for(int i = 0; i < temp.size(); ++i) {
                if(temp[i] == temp[i + 1]) {
                    count++;
                }
                else {
                    ans = ans + to_string(count) + temp[i];
                    count = 1;
                }
            }
            temp = ans;
        }
        return ans;
    }


   


int main() {
	int n;
	while(cin >> n){
		cout << countAndSay(n) << endl;
	}
	system("pause");
	return 0;
} 
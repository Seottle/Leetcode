class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int i = 0;
        while(true) {
            while(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(s[i]);
                i++;
            }
            if(S.empty()){
                return false;
            }
            while(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(!S.empty()) {
                    char tmp = S.top();
                    S.pop();
                    if(tmp == '(' && s[i] == ')') {
                        i++;
                    }
                    else if(tmp == '[' && s[i] == ']') {
                        i++;
                    }
                    else if(tmp == '{' && s[i] == '}') {
                        i++;
                    }
                    else return false;
                }
                else return false;
            }
            if(!S.empty() && i == s.size()) return false;
            if(i == s.size()) break;
        }
        return true;
    }
};
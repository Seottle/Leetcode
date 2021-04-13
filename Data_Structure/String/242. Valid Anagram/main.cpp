//高级解法！
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap;
        for(int i = 0; i < s.size(); ++i) {
            mymap[s[i]]++;
        }
        for(int i = 0; i < t.size(); ++i) {
            mymap[t[i]]--;
        }
        map<char, int> :: iterator it;
        for(it = mymap.begin(); it != mymap.end(); ++it) {
            if(it -> second != 0) return false;
        }
        return true;
    }
};
//低级解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap;
        int lens = s.size();
        int lent = t.size();
        if(lens < lent) {
            for(int i = 0; i < s.size(); ++i) {
                mymap[s[i]]++;
            }
            for(int i = 0; i < t.size(); ++i) {
                if(mymap[t[i]] == 0) {
                    return false;
                }
                mymap[t[i]]--;
            }
            return true;
        }
        else {
            for(int i = 0; i < t.size(); ++i) {
                mymap[t[i]]++;
            }
            for(int i = 0; i < s.size(); ++i) {
                if(mymap[s[i]] == 0) {
                    return false;
                }
                mymap[s[i]]--;
            }
            return true;
        }
    }
};
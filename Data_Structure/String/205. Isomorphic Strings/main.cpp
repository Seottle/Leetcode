class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        char indexS[256];
        char indexT[256];
        memset(indexS, 0, sizeof(indexS));
        memset(indexT, 0, sizeof(indexT));
        for(int i = 0; i < s.size(); ++i) {
            char x = s[i], y = t[i];
            if(indexS[x] != indexT[y]) {
                return false;
            }
            indexS[x] = i + 1;
            indexT[y] = i + 1;
        }
        return true;
    }
};


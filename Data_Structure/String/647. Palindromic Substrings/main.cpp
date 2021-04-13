//中心扩散法！好帅啊！
class Solution {
public:
    int cnt = 0;
    void centerExtend(string s, int start, int end) {
        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
            cnt++;
        }
        return;
    }
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); ++i) {
            centerExtend(s, i, i); // 以一个字符为中心
            centerExtend(s, i, i + 1); // 以两个字符为中心
        }
        return cnt;
    }
};
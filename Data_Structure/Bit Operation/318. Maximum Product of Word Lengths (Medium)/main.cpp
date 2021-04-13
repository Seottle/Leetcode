class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> hash(n);
        //存每个单词的二进制位映射  |= 很关键嗷
        for(int i = 0; i < words.size(); ++i) {
            for(char c : words[i]) {  //  这个方法用在字符串中对应单词的遍历很方便，要学会
                hash[i] |= 1 << (c - 'a');
            } 
        }
        int ans = 0;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                // (hash[i] & hash[j]) == 0说明没有相同
                if((hash[i] & hash[j]) == 0){
                    int x = words[i].size();
                    int y = words[j].size();
                    ans = max(ans, x*y);
                }
            }
        }
        return ans;
    }
};
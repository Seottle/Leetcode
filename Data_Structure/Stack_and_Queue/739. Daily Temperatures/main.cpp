//利用栈存在下标，当栈不空时，判断当前元素与栈顶元素的为下标的值的大小，如果大即满足条件当前元素与栈顶元素的下标之差就是距离。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> S;
        for(int i = 0; i < T.size(); ++i) {
            while(!S.empty() && T[i] > T[S.top()]) {
                int t = S.top();
                S.pop();
                ans[t] = i - t;
            }
            S.push(i);
        }
        return ans;
    }
};
//python 写法
class Solution:    
    def dailyTemperatures(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        ans = [0] * n #初始化ans列表长度为n个0！很关键！！
        for i in range(0, n):
            while stack and heights[i] > heights[stack[-1]]:
                tmp = stack[-1]
                stack.pop(-1)
                ans[tmp] = i - tmp
            stack.append(i)
        return ans


//暴力超时
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        for(int i = 0; i < T.size(); ++i) {
            int day = 1;
            int j;
            for(j = i + 1; j < T.size(); ++j) {
                if(T[j] <= T[i]) {
                    day++;
                    continue;
                }
                break;
            }
            if(j == T.size()) day = 0;
            ans.push_back(day);
        }
        return ans;
    }
};
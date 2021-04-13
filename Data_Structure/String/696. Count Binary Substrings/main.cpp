class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        lst = list(s)
        lst1 = []
        cnt = 1
        for i in range(1, len(lst)) :
            if lst[i] == lst[i - 1] :
                cnt += 1
            else :
                lst1.append(cnt)
                cnt = 1
        lst1.append(cnt)
        ans = 0
        for i in range(1, len(lst1)):
            ans += min(lst1[i - 1], lst1[i])
        return ans
class Solution {
public:
    void reverse(vector<int> &temp, int i, int j) {
        while(i < j) {
            int tmp = temp[i];
            temp[i] = temp[j];
            temp[j] = tmp;
            i++;
            j--;
        }
    }
    vector<int> constructArray(int n, int k) {
        vector<int> temp;
        for(int i = 0; i < n; ++i) {
            temp.push_back(i + 1);
        }
        for(int i = 1; i < k; ++i) {
            reverse(temp, i, n - 1);
        }
        return temp;
    }
};

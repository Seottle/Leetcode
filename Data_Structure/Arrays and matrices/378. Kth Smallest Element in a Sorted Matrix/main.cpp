//堆解法
class Solution {
public:
    struct Point{
        int val, x, y;
        Point(int val_, int x_, int y_) {
            val = val_;
            x = x_;
            y = y_;
        }
        bool operator > (const Point &a) const{
            return this -> val > a.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象
        priority_queue<Point, vector<Point>, greater<Point> > que;
        int n = matrix.size();
        for(int i = 0; i < n; ++i) {
            que.emplace(matrix[i][0], i, 0);
        }
        for(int i = 0; i < k - 1; ++i) {
            Point temp = que.top();
            que.pop();
            if(temp.y != n - 1) {
                que.emplace(matrix[temp.x][temp.y + 1], temp.x, temp.y + 1);
            }
        }
        return que.top().val;
    }
};
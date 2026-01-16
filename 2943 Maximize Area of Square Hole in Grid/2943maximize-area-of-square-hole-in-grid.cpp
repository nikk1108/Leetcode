class Solution {
public:
    int maximizeSquareHoleArea(int h, int w, vector<int>& x, vector<int>& y) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int a = 1, b = 1, c = 1, d = 1;
        
        for (int i = 1; i < x.size(); i++) {
            if (x[i] == x[i - 1] + 1) a++;
            else a = 1;
            b = max(b, a);
        }
        
        for (int i = 1; i < y.size(); i++) {
            if (y[i] == y[i - 1] + 1) c++;
            else c = 1;
            d = max(d, c);
        }
        
        int side = min(b + 1, d + 1);
        return side * side;
    }
};

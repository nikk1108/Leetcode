class Solution {
public:
    int nextBeautifulNumber(int x) {
        while (!chk(++x));
        return x;
    }

private:
    bool chk(int y) {
        vector<int> c(10);
        while (y > 0) {
            int d = y % 10;
            if (d == 0) return false;
            ++c[d];
            y /= 10;
        }
        for (int i = 1; i < 10; ++i)
            if (c[i] && c[i] != i) return false;
        return true;
    }
};

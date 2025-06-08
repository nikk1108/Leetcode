class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> r;
        int c = 1;
        for (int i = 0; i < n; ++i) {
            r.push_back(c);
            if (c * 10 <= n) {
                c *= 10;
            } else {
                while (c % 10 == 9 || c + 1 > n) c /= 10;
                ++c;
            }
        }
        return r;
    }
};

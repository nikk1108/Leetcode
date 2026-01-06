class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long s = 0;
        int neg = 0, mn = INT_MAX;

        for (auto &r : mat) {
            for (int x : r) {
                s += abs(x);
                if (x < 0) neg++;
                mn = min(mn, abs(x));
            }
        }
        if (neg % 2) s -= 2LL * mn;
        return s;
    }
};

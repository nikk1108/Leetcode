class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto &q : queries) {
            int l = q[0], r = q[1];
           
            ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    long getOperations(int n) {
        if (n <= 0) return 0;
        long res = 0;
        int ops = 0;
        for (long p = 1; p <= n; p *= 4) {
            int l = p;
            int r = min<long>(n, p * 4 - 1);
            res += (long)(r - l + 1) * (++ops);
        }
        return res;
    }
};

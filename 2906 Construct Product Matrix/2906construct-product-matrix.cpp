class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size(), n = grid[0].size();
        int sz = m * n;

        vector<int> pre(sz + 1, 1), suf(sz + 1, 1);

        for (int i = 0; i < sz; i++) {
            int r = i / n, c = i % n;
            pre[i + 1] = (1LL * pre[i] * grid[r][c]) % mod;
        }

        for (int i = sz - 1; i >= 0; i--) {
            int r = i / n, c = i % n;
            suf[i] = (1LL * suf[i + 1] * grid[r][c]) % mod;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < sz; i++) {
            int r = i / n, c = i % n;
            ans[r][c] = (1LL * pre[i] * suf[i + 1]) % mod;
        }

        return ans;
    }
};
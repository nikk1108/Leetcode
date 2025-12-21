class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a.size();
        int m = a[0].size();
        int del = 0;

        vector<bool> ok(n - 1, false);

        for (int c = 0; c < m; c++) {
            int r;
            for (r = 0; r + 1 < n; r++) {
                if (!ok[r] && a[r][c] > a[r + 1][c]) {
                    del++;
                    break;
                }
            }

            if (r + 1 == n) {
                for (r = 0; r + 1 < n; r++) {
                    if (!ok[r] && a[r][c] < a[r + 1][c])
                        ok[r] = true;
                }
            }
        }

        return del;
    }
};

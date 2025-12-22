class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> dp(m, 1);
        int best = 1;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            best = max(best, dp[j]);
        }

        return m - best;
    }
};

class Solution {
public:
    int maxProductPath(vector<vector<int>>& mat) {
        const int MOD = 1'000'000'007;
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<long>> minDP(rows, vector<long>(cols));
        vector<vector<long>> maxDP(rows, vector<long>(cols));

        minDP[0][0] = maxDP[0][0] = mat[0][0];

        for (int i = 1; i < rows; ++i)
            minDP[i][0] = maxDP[i][0] = minDP[i - 1][0] * mat[i][0];

        for (int j = 1; j < cols; ++j)
            minDP[0][j] = maxDP[0][j] = minDP[0][j - 1] * mat[0][j];

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (mat[i][j] < 0) {
                    minDP[i][j] = max(maxDP[i - 1][j], maxDP[i][j - 1]) * mat[i][j];
                    maxDP[i][j] = min(minDP[i - 1][j], minDP[i][j - 1]) * mat[i][j];
                } else {
                    minDP[i][j] = min(minDP[i - 1][j], minDP[i][j - 1]) * mat[i][j];
                    maxDP[i][j] = max(maxDP[i - 1][j], maxDP[i][j - 1]) * mat[i][j];
                }
            }
        }

        long res = max(minDP.back().back(), maxDP.back().back());
        return res < 0 ? -1 : res % MOD;
    }
};
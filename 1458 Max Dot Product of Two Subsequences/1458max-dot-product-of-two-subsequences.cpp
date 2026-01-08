class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        const int NEG = -1e9;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, NEG));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int prod = a[i-1] * b[j-1];
                dp[i][j] = max({
                    prod,
                    dp[i-1][j-1] + prod,
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }
        return dp[n][m];
    }
};

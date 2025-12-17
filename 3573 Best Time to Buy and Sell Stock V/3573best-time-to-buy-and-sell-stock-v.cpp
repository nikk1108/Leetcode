class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG = -4e18;

        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> nxt = dp;

            for (int j = 0; j <= k; j++) {

                if (dp[j][0] != NEG) {
                    if (j < k) {
                        nxt[j + 1][1] = max(nxt[j + 1][1], dp[j][0] - price);
                        nxt[j + 1][2] = max(nxt[j + 1][2], dp[j][0] + price);
                    }
                }

                if (dp[j][1] != NEG) {
                    nxt[j][0] = max(nxt[j][0], dp[j][1] + price);
                    nxt[j][1] = max(nxt[j][1], dp[j][1]);
                }

                if (dp[j][2] != NEG) {
                    nxt[j][0] = max(nxt[j][0], dp[j][2] - price);
                    nxt[j][2] = max(nxt[j][2], dp[j][2]);
                }
            }

            dp.swap(nxt);
        }

        long long ans = 0;
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[j][0]);
        }
        return ans;
    }
};

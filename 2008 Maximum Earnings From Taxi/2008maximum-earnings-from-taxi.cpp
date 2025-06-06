#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& r) {
        sort(r.begin(), r.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int m = r.size();
        vector<long long> dp(m + 1, 0);
        vector<int> ends(m);

        for (int i = 0; i < m; ++i) ends[i] = r[i][1];

        for (int i = 0; i < m; ++i) {
            int s = r[i][0], e = r[i][1], t = r[i][2];
            long long earn = e - s + t;

            int idx = upper_bound(ends.begin(), ends.end(), s) - ends.begin() - 1;
            if (idx >= 0) earn += dp[idx + 1];

            dp[i + 1] = max(dp[i], earn);
        }

        return dp[m];
    }
};

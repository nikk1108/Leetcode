class Solution {
 public:
  int possibleStringCount(string s, int k) {
    const vector<int> g = groupCounts(s);
    const int total =
        accumulate(g.begin(), g.end(), 1L,
                   [](long a, int b) { return a * b % MOD; });

    if (k <= g.size())
      return total;

    vector<int> dp(k);
    dp[0] = 1;

    for (int i = 0; i < g.size(); ++i) {
      vector<int> next(k);
      int sum = 0, cnt = g[i];
      for (int j = i; j < k; ++j) {
        next[j] = (next[j] + sum) % MOD;
        sum = (sum + dp[j]) % MOD;
        if (j >= cnt)
          sum = (sum - dp[j - cnt] + MOD) % MOD;
      }
      dp = move(next);
    }

    int invalid =
        accumulate(dp.begin(), dp.end(), 0,
                   [](int a, int b) { return (a + b) % MOD; });

    return (total - invalid + MOD) % MOD;
  }

 private:
  static constexpr int MOD = 1'000'000'007;

  vector<int> groupCounts(const string& s) {
    vector<int> res;
    int cnt = 1;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        ++cnt;
      } else {
        res.push_back(cnt);
        cnt = 1;
      }
    }
    res.push_back(cnt);
    return res;
  }
};

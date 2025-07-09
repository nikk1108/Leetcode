class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int maxAttend) {
    vector<vector<int>> dp(events.size(), vector<int>(maxAttend + 1, -1));
    ranges::sort(events);
    return dfs(events, 0, maxAttend, dp);
  }

 private:
  int dfs(const vector<vector<int>>& events, int index, int remaining,
          vector<vector<int>>& dp) {
    if (remaining == 0 || index == events.size())
      return 0;
    if (dp[index][remaining] != -1)
      return dp[index][remaining];

    auto it = upper_bound(
        events.begin() + index, events.end(), events[index][1],
        [](int endTime, const vector<int>& event) {
          return event[0] > endTime;
        });
    int nextIndex = distance(events.begin(), it);

    return dp[index][remaining] = max(events[index][2] + dfs(events, nextIndex, remaining - 1, dp),
                                      dfs(events, index + 1, remaining, dp));
  }
};

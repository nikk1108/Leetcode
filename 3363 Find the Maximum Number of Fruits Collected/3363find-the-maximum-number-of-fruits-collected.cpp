class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& grid) {
    return collectDiag(grid) + collectTopRight(grid) + collectBottomLeft(grid) -
           2 * grid.back().back();
  }

 private:
  int collectDiag(const vector<vector<int>>& grid) {
    int n = grid.size(), sum = 0;
    for (int i = 0; i < n; ++i)
      sum += grid[i][i];
    return sum;
  }

  int collectTopRight(const vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][n - 1] = grid[0][n - 1];

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (r >= c && !(r == n - 1 && c == n - 1))
          continue;
        for (auto [dr, dc] : vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}}) {
          int pr = r - dr, pc = c - dc;
          if (pr < 0 || pr == n || pc < 0 || pc == n)
            continue;
          if (pr < pc && pc < n - 1 - pr)
            continue;
          dp[r][c] = max(dp[r][c], dp[pr][pc] + grid[r][c]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }

  int collectBottomLeft(const vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][0] = grid[n - 1][0];

    for (int c = 0; c < n; ++c) {
      for (int r = 0; r < n; ++r) {
        if (r <= c && !(r == n - 1 && c == n - 1))
          continue;
        for (auto [dr, dc] : vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}}) {
          int pr = r - dr, pc = c - dc;
          if (pr < 0 || pr == n || pc < 0 || pc == n)
            continue;
          if (pc < pr && pr < n - 1 - pc)
            continue;
          dp[r][c] = max(dp[r][c], dp[pr][pc] + grid[r][c]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }
};

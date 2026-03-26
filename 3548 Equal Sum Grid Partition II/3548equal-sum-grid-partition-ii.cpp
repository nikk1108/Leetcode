class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long tot = 0;

        for (auto& r : grid) {
            for (int x : r) tot += x;
        }

        const int mx = 100000;

        {
            vector<int> up(mx + 1, 0), down(mx + 1, 0);
            long long s = 0;

            for (auto& r : grid) {
                for (int x : r) down[x]++;
            }

            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    int x = grid[i][j];
                    s += x;
                    up[x]++;
                    down[x]--;
                }

                long long a = s, b = tot - s;
                if (a == b) return true;

                long long d = llabs(a - b);
                if (d > mx) continue;

                if (a > b) {
                    int h = i + 1;

                    if (h == 1) {
                        if (grid[0][0] == d || grid[0][n - 1] == d) return true;
                    } else if (n == 1) {
                        if (grid[0][0] == d || grid[i][0] == d) return true;
                    } else {
                        if (up[d] > 0) return true;
                    }
                } else {
                    int h = m - i - 1;
                    int r1 = i + 1, r2 = m - 1;

                    if (h == 1) {
                        if (grid[r1][0] == d || grid[r1][n - 1] == d) return true;
                    } else if (n == 1) {
                        if (grid[r1][0] == d || grid[r2][0] == d) return true;
                    } else {
                        if (down[d] > 0) return true;
                    }
                }
            }
        }

        {
            vector<int> left(mx + 1, 0), right(mx + 1, 0);
            long long s = 0;

            for (auto& r : grid) {
                for (int x : r) right[x]++;
            }

            for (int j = 0; j < n - 1; j++) {
                for (int i = 0; i < m; i++) {
                    int x = grid[i][j];
                    s += x;
                    left[x]++;
                    right[x]--;
                }

                long long a = s, b = tot - s;
                if (a == b) return true;

                long long d = llabs(a - b);
                if (d > mx) continue;

                if (a > b) {
                    int w = j + 1;

                    if (w == 1) {
                        if (grid[0][0] == d || grid[m - 1][0] == d) return true;
                    } else if (m == 1) {
                        if (grid[0][0] == d || grid[0][j] == d) return true;
                    } else {
                        if (left[d] > 0) return true;
                    }
                } else {
                    int w = n - j - 1;
                    int c1 = j + 1, c2 = n - 1;

                    if (w == 1) {
                        if (grid[0][c1] == d || grid[m - 1][c1] == d) return true;
                    } else if (m == 1) {
                        if (grid[0][c1] == d || grid[0][c2] == d) return true;
                    } else {
                        if (right[d] > 0) return true;
                    }
                }
            }
        }

        return false;
    }
};
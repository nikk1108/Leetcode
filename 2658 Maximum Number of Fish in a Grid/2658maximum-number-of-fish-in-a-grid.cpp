class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxFish = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    int currSum = dfs(grid, visited, i, j, m, n);
                    maxFish = max(maxFish, currSum);
                }
            }
        }

        return maxFish;
    }

private:
    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        int sum = grid[r][c];

        sum += dfs(grid, visited, r + 1, c, m, n);
        sum += dfs(grid, visited, r - 1, c, m, n);
        sum += dfs(grid, visited, r, c + 1, m, n);
        sum += dfs(grid, visited, r, c - 1, m, n);

        return sum;
    }
};

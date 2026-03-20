class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> res(rows - k + 1, vector<int>(cols - k + 1, 0));

        for (int i = 0; i <= rows - k; ++i) {
            for (int j = 0; j <= cols - k; ++j) {

                vector<int> values;

                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        values.push_back(grid[r][c]);
                    }
                }

                sort(values.begin(), values.end());

                int minDiff = INT_MAX;

                for (int t = 1; t < values.size(); ++t) {
                    if (values[t] != values[t - 1]) {
                        minDiff = min(minDiff, values[t] - values[t - 1]);
                    }
                }

                res[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }

        return res;
    }
};
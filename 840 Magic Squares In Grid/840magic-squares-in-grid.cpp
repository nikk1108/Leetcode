class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        auto isMagic = [&](int r, int c) {
            if (r + 2 >= rows || c + 2 >= cols) return 0;

            vector<int> used(10, 0);
            vector<int> rowSum(3, 0);
            vector<int> colSum(3, 0);
            int diag1 = 0, diag2 = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int val = grid[r + i][c + j];
                    if (val < 1 || val > 9 || used[val]) return 0;
                    used[val] = 1;
                    rowSum[i] += val;
                    colSum[j] += val;
                    if (i == j) diag1 += val;
                    if (i + j == 2) diag2 += val;
                }
            }

            if (diag1 != diag2) return 0;

            for (int k = 0; k < 3; k++) {
                if (rowSum[k] != diag1 || colSum[k] != diag1) return 0;
            }

            return 1;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result += isMagic(i, j);
            }
        }

        return result;
    }
};

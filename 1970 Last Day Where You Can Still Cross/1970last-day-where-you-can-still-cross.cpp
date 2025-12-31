class Solution {
public:
    int latestDayToCross(int rows, int cols, vector<vector<int>>& cells) {
        int dir[5] = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) -> bool {
            vector<vector<int>> grid(rows, vector<int>(cols, 0));

            for (int i = 0; i < day; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int, int>> q;

            for (int c = 0; c < cols; ++c) {
                if (grid[0][c] == 0) {
                    q.emplace(0, c);
                    grid[0][c] = 1;
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == rows - 1) return true;

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0) {
                        q.emplace(nr, nc);
                        grid[nr][nc] = 1;
                    }
                }
            }

            return false;
        };

        auto blocked = [&](int day) -> bool {
            return !canCross(day);
        };

        int left = 1, right = cells.size(), firstBlocked = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (blocked(mid)) {
                firstBlocked = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstBlocked - 1;
    }
};

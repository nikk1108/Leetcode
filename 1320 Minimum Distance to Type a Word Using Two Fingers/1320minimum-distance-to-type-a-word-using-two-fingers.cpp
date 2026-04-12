class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(n, -1)));
        return solve(word, 26, 26, 0, dp);
    }

private:
    int solve(const string &word, int left, int right, int idx,
              vector<vector<vector<int>>> &dp) {
        if (idx == word.size()) return 0;

        if (dp[left][right][idx] != -1)
            return dp[left][right][idx];

        int curr = word[idx] - 'A';

        int useLeft = getDist(left, curr) + solve(word, curr, right, idx + 1, dp);
        int useRight = getDist(right, curr) + solve(word, left, curr, idx + 1, dp);

        return dp[left][right][idx] = min(useLeft, useRight);
    }

    int getDist(int from, int to) {
        if (from == 26) return 0;

        int r1 = from / 6, c1 = from % 6;
        int r2 = to / 6, c2 = to % 6;

        return abs(r1 - r2) + abs(c1 - c2);
    }
};
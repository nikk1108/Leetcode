class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h[j] = (mat[i][j] == 0) ? 0 : h[j] + 1;
            }

            vector<int> temp = h;
            sort(temp.begin(), temp.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }
};
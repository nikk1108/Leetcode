class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        
        long long s = 0;
        for (auto &r : g)
            for (auto &x : r)
                s += x;
        
        if (s % 2) return false;
        
        long long t = s / 2;
        
        long long cur = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                cur += g[i][j];
            if (cur == t) return true;
        }
        
        cur = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                cur += g[i][j];
            if (cur == t) return true;
        }
        
        return false;
    }
};
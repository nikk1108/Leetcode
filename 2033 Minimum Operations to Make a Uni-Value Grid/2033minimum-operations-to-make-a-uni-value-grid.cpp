class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        
        for (auto &row : grid) {
            for (auto &val : row) {
                v.push_back(val);
            }
        }
        
        int r = v[0] % x;
        for (auto &val : v) {
            if (val % x != r) return -1;
        }
        
        sort(v.begin(), v.end());
        
        int n = v.size();
        int median = v[n / 2];
        
        int ops = 0;
        for (auto &val : v) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};
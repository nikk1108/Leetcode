class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m), c(n);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j]) {
                    r[i]++;
                    c[j]++;
                }

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] && r[i] == 1 && c[j] == 1)
                    ans++;

        return ans;
    }
};
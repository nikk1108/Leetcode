class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> rs(n+1, vector<int>(m+1)), cs(n+1, vector<int>(m+1));
        vector<vector<int>> d1(n+1, vector<int>(m+1)), d2(n+2, vector<int>(m+2));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rs[i+1][j+1] = rs[i+1][j] + g[i][j];
                cs[i+1][j+1] = cs[i][j+1] + g[i][j];
                d1[i+1][j+1] = d1[i][j] + g[i][j];
                d2[i+1][j+1] = d2[i][j+2] + g[i][j];
            }
        }

        int ans = 1;
        for(int k=2;k<=min(n,m);k++){
            for(int i=0;i+k<=n;i++){
                for(int j=0;j+k<=m;j++){
                    int s = rs[i+1][j+k] - rs[i+1][j];
                    bool ok = true;
                    for(int x=i;x<i+k && ok;x++){
                        if(rs[x+1][j+k] - rs[x+1][j] != s) ok=false;
                    }
                    for(int y=j;y<j+k && ok;y++){
                        if(cs[i+k][y+1] - cs[i][y+1] != s) ok=false;
                    }
                    if(!ok) continue;
                    if(d1[i+k][j+k] - d1[i][j] != s) continue;
                    if(d2[i+k][j+1] - d2[i][j+k+1] != s) continue;
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};

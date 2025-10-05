#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int r = arr.size(), c = arr[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pac(r, vector<int>(c)), atl(r, vector<int>(c));
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int x, int y, vector<vector<int>>& vis) {
            vis[x][y] = 1;
            int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
            for(int k=0;k<4;k++) {
                int nx = x+dx[k], ny = y+dy[k];
                if(nx>=0 && ny>=0 && nx<r && ny<c && !vis[nx][ny] && arr[nx][ny]>=arr[x][y]) {
                    dfs(nx,ny,vis);
                }
            }
        };
        for(int i=0;i<r;i++) {
            dfs(i,0,pac);
            dfs(i,c-1,atl);
        }
        for(int j=0;j<c;j++) {
            dfs(0,j,pac);
            dfs(r-1,j,atl);
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};

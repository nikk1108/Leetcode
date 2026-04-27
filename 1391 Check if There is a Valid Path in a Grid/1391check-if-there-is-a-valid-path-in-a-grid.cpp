class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<pair<int,int>>> dir = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            
            if(r == m-1 && c == n-1) return true;
            
            for(auto [dr,dc] : dir[grid[r][c]]) {
                int nr = r + dr, nc = c + dc;
                
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || vis[nr][nc]) continue;
                
                for(auto [ndr,ndc] : dir[grid[nr][nc]]) {
                    if(nr + ndr == r && nc + ndc == c) {
                        vis[nr][nc] = true;
                        q.push({nr,nc});
                        break;
                    }
                }
            }
        }
        
        return false;
    }
};
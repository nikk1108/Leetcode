#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({g[0][0], 0, 0});
        int res = 0;
        int d[5] = {1,0,-1,0,1};
        while (!pq.empty()) {
            auto v = pq.top(); pq.pop();
            int h = v[0], x = v[1], y = v[2];
            res = max(res, h);
            if (x == n - 1 && y == n - 1) return res;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i+1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({g[nx][ny], nx, ny});
                }
            }
        }
        return res;
    }
};

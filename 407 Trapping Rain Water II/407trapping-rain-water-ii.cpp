#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            pq.push({h[i][0],{i,0}});
            pq.push({h[i][n-1],{i,n-1}});
            vis[i][0]=vis[i][n-1]=1;
        }
        for(int j=1;j<n-1;j++){
            pq.push({h[0][j],{0,j}});
            pq.push({h[m-1][j],{m-1,j}});
            vis[0][j]=vis[m-1][j]=1;
        }
        int ans=0, mx=0;
        vector<int> dir={1,0,-1,0,1};
        while(!pq.empty()){
            auto [ht,p]=pq.top(); pq.pop();
            int x=p.first,y=p.second;
            mx=max(mx,ht);
            for(int k=0;k<4;k++){
                int nx=x+dir[k], ny=y+dir[k+1];
                if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny]) continue;
                vis[nx][ny]=1;
                if(h[nx][ny]<mx) ans+=mx-h[nx][ny];
                pq.push({h[nx][ny],{nx,ny}});
            }
        }
        return ans;
    }
};

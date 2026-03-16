class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                s.insert(grid[i][j]);

                for(int d=1;i-d>=0 && i+d<m && j-d>=0 && j+d<n;d++){
                    int sum=0;

                    int x=i-d,y=j;
                    for(int k=0;k<d;k++) sum+=grid[x+k][y+k];

                    x=i;y=j+d;
                    for(int k=0;k<d;k++) sum+=grid[x+k][y-k];

                    x=i+d;y=j;
                    for(int k=0;k<d;k++) sum+=grid[x-k][y-k];

                    x=i;y=j-d;
                    for(int k=0;k<d;k++) sum+=grid[x-k][y+k];

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        auto it=s.rbegin();

        for(int i=0;i<3 && it!=s.rend();i++,it++)
            ans.push_back(*it);

        return ans;
    }
};
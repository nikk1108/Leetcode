class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> v(n, INT_MAX);
        v[0] = 0;
        for(auto &r : restrictions) v[r[0]] = min(v[r[0]], r[1]);
        
        for(int i=1;i<n;i++) v[i] = min(v[i], v[i-1]+diff[i-1]);
        for(int i=n-2;i>=0;i--) v[i] = min(v[i], v[i+1]+diff[i]);
        
        vector<int> pr(n,0);
        pr[0] = 0;
        for(int i=1;i<n;i++) pr[i] = min(pr[i-1]+diff[i-1], v[i]);
        
        vector<int> answer(n,0);
        answer[n-1] = pr[n-1];
        for(int i=n-2;i>=0;i--) answer[i] = min(answer[i+1]+diff[i], v[i]);
        
        int res=0;
        for(int i=0;i<n;i++) res = max(res, min(pr[i], answer[i]));
        return res;
    }
};

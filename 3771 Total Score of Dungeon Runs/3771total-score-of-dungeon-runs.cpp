class Solution {
public:
    long long totalScore(int hp, vector<int>& d, vector<int>& rq ) {
       int n=d.size();
        vector <long long>pr(n+1,0);
        for (int i=1;i<=n;i++) pr[i]=pr[i-1]+d[i-1];
     long long ans =0;
           for (int j=1;j<=n;j++){
  long long s=(long long)hp-rq[j-1];
          long long l=pr[j]-s;
               int idx= lower_bound(pr.begin(),pr.begin()+j,l)-pr.begin();
                ans += (j - idx);
           
            
        }
        return ans;
    }
};
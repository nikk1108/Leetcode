class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        vector<int> dr= nums;
        int n= nums.size();
        int ans=n+1;
          
          int sum=0;
        int i=0;
        vector<int> fr(100001,0);
             for(int j=0;j<n;j++)
                 { if (fr[dr[j]]==0) sum += dr[j];
                  fr[dr[j]]++;
                  while(sum>=k)
                      {   ans=min(ans,j-i+1);
                        fr[dr[i]]--;  
                  if(fr[dr[i]]==0) sum = sum-dr[i];
                  i++;
                 }
    }
        if(ans==n+1)
            return -1;
        else return ans;
    }
};
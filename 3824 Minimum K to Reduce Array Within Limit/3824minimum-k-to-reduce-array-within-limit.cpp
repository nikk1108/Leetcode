class Solution {
public:
    int minimumK(vector<int>& nums) {
        vector<int> vn= nums;
        long long l=1,r=100000,ans=r;
        auto ok= [&](long long k)
        {
            long long op=0;
            for (int x:vn){
                op+= (x+k-1)/k;
                if(op>k*k)
                return false;
            }
            return op<=k*k;
        };
        while(l<=r)
            {
                long long m= (l+r)>>1;
                if(ok(m)){
                    ans=m;
                    r=m-1;
                }
                else {
                    l=m+1;
                }
            }
        return ans;
    }
};
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n= nums.size();
        vector<pair<int,int>> tor(n);
        for (int i=0;i<n;i++)
            tor[i]={nums[i],colors[i]};
        long long ct=0;
        long long pv=0;
        for(int i=0;i<n;i++)
            {
                long long nt=0;
                if (i==0) nt= nums[i];
                else {
                    if (colors[i]== colors[i-1])
                        nt= pv+ nums[i];
                    else nt=max(ct,pv)+ nums[i];
                }
                long long ns= max(ct,pv);
                ct= nt;
                pv=ns;
            }
        return max(ct,pv);
    }
};
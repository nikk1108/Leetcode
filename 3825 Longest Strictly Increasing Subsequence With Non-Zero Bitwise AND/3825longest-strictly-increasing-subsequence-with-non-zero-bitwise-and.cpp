class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> sc= nums;
      int ans=0;
        for(int b=0;b<31;b++)
            {
                vector<int> li;
                for (int x: sc)
                    {
                        if((x>>b)&1){
                            auto it= lower_bound(li.begin(),li.end(),x);
                             if (it == li.end()) li.push_back(x);
                             else *it = x;
                        }
                    }
                            ans = max(ans, (int)li.size());

            }
        return ans;
        
    }
};
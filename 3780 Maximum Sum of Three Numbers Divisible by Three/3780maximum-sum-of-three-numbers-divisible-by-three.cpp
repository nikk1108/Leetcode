class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> m = nums;
          vector<int> r0,r1,r2;
        for (int x:m){
            if(x % 3 == 0) r0.push_back(x);
             else if(x % 3 == 1) r1.push_back(x);
            else  r2.push_back(x);
        }
        sort (r0.begin(),r0.end(),greater<int>());
          sort (r1.begin(),r1.end(),greater<int>());
          sort (r2.begin(),r2.end(),greater<int>());
        int ans =0;
        if(r0.size()>=3) ans = r0[0]+r0[1]+r0[2];
        if(r1.size()>=3) ans = max(ans, r1[0]+r1[1]+r1[2]);
            if(r2.size()>=3)  ans = max(ans, r2[0]+r2[1]+r2[2]);
        if(r0.size() >= 1 && r1.size() >= 1 && r2.size() >= 1) 
            ans = max(ans, r0[0]+r1[0]+r2[0]);
        return ans;
    }
};
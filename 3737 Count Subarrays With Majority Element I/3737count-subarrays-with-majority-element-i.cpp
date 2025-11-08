class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
    int n=nums.size();
        int r=0;
        for (int i=0;i<n;i++)
            {
                int ct=0;
                int l =0;
                for (int j=i;j<n;j++)
                    {       l++;
                if (nums[j]==target)
                    ct++;
                int d=l;
                if (ct>l/2)
                    r++;
    }
            }
        return r;
    }
};
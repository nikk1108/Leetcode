class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int>ans;
       int n= nums.size();
       for (int i=0;i<n;i++) 
       {
      int val=nums[i];
      if(val<0) val=-val;
      int index= val-1;
      if(nums[index]<0) ans.push_back(val);
      else nums[index]=-nums[index];

       }
       return ans;
    }
};
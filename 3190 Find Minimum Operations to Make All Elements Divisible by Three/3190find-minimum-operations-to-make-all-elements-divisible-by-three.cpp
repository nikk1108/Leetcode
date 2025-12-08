class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      int ans=0;
      for (int i=0;i<nums.size();i++)
  {  int x = nums[i];
            int r = x % 3;
            if (r != 0) ans ++;
    } return ans; }
};
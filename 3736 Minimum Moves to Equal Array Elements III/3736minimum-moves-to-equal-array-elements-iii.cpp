class Solution {
public:
    int minMoves(vector<int>& nums) {
      int min= nums[0];
        int sum=0;
        for (int s :nums)
             if (s>min)
            min = s;
             for (int s :nums)
            sum= sum+ (min-s);
            
     return sum; }
};
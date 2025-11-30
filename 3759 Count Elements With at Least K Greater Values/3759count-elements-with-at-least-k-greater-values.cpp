class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int answer=0;
        for (int x:nums)
              if (n-(upper_bound(nums.begin(),nums.end(),x)-nums.begin())>=k )
         answer++; 
    return answer;
    }
};
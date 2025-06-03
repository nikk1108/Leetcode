class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); ++i) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            if ((a + c) * 2 == b)
                ++count;
        }
        return count;
    }
};

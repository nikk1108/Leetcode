class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cur = 0, pre = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cur++;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                mx = max({mx, cur / 2, min(pre, cur)});
                pre = cur;
                cur = 0;
            }
        }
        return mx >= k;
    }
};

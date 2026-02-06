class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while ((long long)nums[l] * k < nums[r]) l++;
            ans = max(ans, r - l + 1);
        }
        return n - ans;
    }
};

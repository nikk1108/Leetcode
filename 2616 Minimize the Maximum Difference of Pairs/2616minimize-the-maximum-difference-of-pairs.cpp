class Solution {
public:
    bool canForm(vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ++count;
                ++i;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front(), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canForm(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

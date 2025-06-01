class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);  // difference array to track number of times each index is included in any query

        // Build difference array from query ranges
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            freq[l]++;
            if (r + 1 < n) freq[r + 1]--;
        }

        // Compute prefix sum to get count of decrements available at each index
        for (int i = 1; i < n; ++i) {
            freq[i] += freq[i - 1];
        }

        // Check if each number can be decremented down to zero
        for (int i = 0; i < n; ++i) {
            if (freq[i] < nums[i]) return false;  // not enough decrements available
        }

        return true;
    }
};




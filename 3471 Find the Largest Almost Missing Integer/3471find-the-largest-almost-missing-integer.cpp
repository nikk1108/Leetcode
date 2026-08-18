class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i + k <= nums.size(); ++i) {
            unordered_set<int> s(nums.begin() + i, nums.begin() + i + k);

            for (int x : s)
                ++freq[x];
        }

        int ans = -1;

        for (auto &[x, f] : freq) {
            if (f == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        vector<long long> mn(k, LLONG_MAX);
        long long ans = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;
            if (mn[mod] != LLONG_MAX)
                ans = max(ans, pref[i] - mn[mod]);
            mn[mod] = min(mn[mod], pref[i]);
        }

        return ans;
    }
};

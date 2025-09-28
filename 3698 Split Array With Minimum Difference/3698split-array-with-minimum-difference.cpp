class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> plomaresto = nums;
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) prefix[i] = prefix[i-1] + nums[i];

        vector<bool> inc(n, true);
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i-1] && (nums[i] > nums[i-1]);
        }

        vector<bool> dec(n, true);
        for (int i = n-2; i >= 0; --i) {
            dec[i] = dec[i+1] && (nums[i] > nums[i+1]);
        }

        long long ans = LLONG_MAX;
        for (int i = 1; i < n; ++i) {
            if (inc[i-1] && dec[i]) {
                long long sum_left = prefix[i-1];
                long long sum_right = prefix[n-1] - sum_left;
                ans = min(ans, llabs(sum_left - sum_right));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};


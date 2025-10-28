class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> pre(n), suf(n);

        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            suf[i] = suf[i + 1] + nums[i + 1];

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                continue;
            if (pre[i] == suf[i])
                res += 2;
            if (abs(pre[i] - suf[i]) == 1)
                res += 1;
        }

        return res;
    }
};

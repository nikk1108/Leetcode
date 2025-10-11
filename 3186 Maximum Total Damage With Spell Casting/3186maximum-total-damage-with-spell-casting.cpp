class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int sz = power.size();
        unordered_map<int, int> valFreq;
        for (int x : power) valFreq[x]++;
        vector<int> nxt(sz);
        for (int i = 0; i < sz; ++i)
            nxt[i] = upper_bound(power.begin() + i + 1, power.end(), power[i] + 2) - power.begin();
        vector<long long> memo(sz + 1, -1);
        return compute(0, power, valFreq, nxt, memo, sz);
    }

private:
    long long compute(int idx,
                      const vector<int>& arr,
                      const unordered_map<int, int>& freq,
                      const vector<int>& jump,
                      vector<long long>& dp,
                      int len) {
        if (idx >= len) return 0;
        if (dp[idx] != -1) return dp[idx];
        int val = arr[idx];
        int count = freq.at(val);
        long long skip = compute(idx + count, arr, freq, jump, dp, len);
        long long take = 1LL * val * count + compute(jump[idx], arr, freq, jump, dp, len);
        return dp[idx] = max(skip, take);
    }
};

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = LLONG_MIN;
        int count = 0;
        for (int x : nums) {
            long long low = x - k;
            long long high = x + k;
            long long candidate = max(low, prev + 1);
            if (candidate <= high) {
                prev = candidate;
                count++;
            }
        }
        return count;
    }
};

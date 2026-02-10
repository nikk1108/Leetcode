class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            int e = 0, o = 0;
            for (int j = i; j < n; j++) {
                if (!s.count(nums[j])) {
                    s.insert(nums[j]);
                    nums[j] & 1 ? o++ : e++;
                }
                if (e == o) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

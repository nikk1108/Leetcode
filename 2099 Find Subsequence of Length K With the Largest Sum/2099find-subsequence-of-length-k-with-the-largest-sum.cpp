class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i)
            v.emplace_back(nums[i], i);
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });
        sort(v.begin(), v.begin() + k, [](auto& a, auto& b) {
            return a.second < b.second;
        });
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(v[i].first);
        return res;
    }
};

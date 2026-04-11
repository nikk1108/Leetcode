class Solution {
public:
    long long minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        long long ans = LLONG_MAX;
        bool found = false;

        for (auto &it : mp) {
            vector<int> &pos = it.second;

            if (pos.size() < 3) continue;

            found = true;

            for (int i = 0; i + 2 < pos.size(); i++) {
                long long dist = 2LL * (pos[i + 2] - pos[i]);
                ans = min(ans, dist);
            }
        }

        return found ? ans : -1;
    }
};
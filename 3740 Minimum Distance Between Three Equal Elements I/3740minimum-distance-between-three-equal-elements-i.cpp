class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            if (pos.size() < 3) continue;

            for (int i = 0; i < pos.size(); i++) {
                for (int j = i + 2; j < pos.size(); j++) {
                    ans = min(ans, 2 * (pos[j] - pos[i]));
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
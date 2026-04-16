class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, INT_MAX);

      
        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int m = pos.size();

            if (m == 1) {
                best[pos[0]] = -1;
                continue;
            }

            for (int i = 0; i < m; i++) {
                int cur = pos[i];

                int left = pos[(i - 1 + m) % m];
                int right = pos[(i + 1) % m];

                int d1 = abs(cur - left);
                d1 = min(d1, n - d1);

                int d2 = abs(cur - right);
                d2 = min(d2, n - d2);

                best[cur] = min(d1, d2);
            }
        }

       
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};
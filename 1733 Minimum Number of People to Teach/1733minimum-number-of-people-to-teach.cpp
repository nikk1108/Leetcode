class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> lang(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) lang[i + 1].insert(l);
        }
        vector<pair<int, int>> need;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int l : lang[u]) {
                if (lang[v].count(l)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) need.push_back({u, v});
        }
        if (need.empty()) return 0;
        int ans = m;
        for (int l = 1; l <= n; l++) {
            unordered_set<int> st;
            for (auto& [u, v] : need) {
                if (!lang[u].count(l)) st.insert(u);
                if (!lang[v].count(l)) st.insert(v);
            }
            ans = min(ans, (int)st.size());
        }
        return ans;
    }
};

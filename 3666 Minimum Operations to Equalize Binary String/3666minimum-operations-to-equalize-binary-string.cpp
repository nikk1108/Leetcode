class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int z = 0;
        for (char c : s) if (c == '0') z++;

        vector<set<int>> vis(2);
        for (int i = 0; i <= n; i++) vis[i & 1].insert(i);
        vis[z & 1].erase(z);

        queue<int> qu;
        qu.push(z);

        int steps = 0;

        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                int cur = qu.front();
                qu.pop();

                if (cur == 0) return steps;

                int L = cur + k - 2 * min(cur, k);
                int R = cur + k - 2 * max(k - n + cur, 0);

                auto &st = vis[L & 1];
                auto it = st.lower_bound(L);

                while (it != st.end() && *it <= R) {
                    qu.push(*it);
                    it = st.erase(it);
                }
            }
            steps++;
        }
        return -1;
    }
};
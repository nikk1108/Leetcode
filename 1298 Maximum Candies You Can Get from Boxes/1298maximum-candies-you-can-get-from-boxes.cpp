class Solution {
public:
    int maxCandies(vector<int>& st, vector<int>& c, vector<vector<int>>& k,
                   vector<vector<int>>& cb, vector<int>& ib) {
        int n = st.size(), ans = 0;
        vector<bool> hb(n, false), op(n, false);
        queue<int> q;

        for (int b : ib) {
            hb[b] = true;
            if (st[b]) q.push(b);
        }

        while (!q.empty()) {
            int b = q.front(); q.pop();
            if (op[b]) continue;
            op[b] = true;
            ans += c[b];

            for (int x : k[b]) {
                if (!st[x]) {
                    st[x] = 1;
                    if (hb[x] && !op[x]) q.push(x);
                }
            }

            for (int x : cb[b]) {
                hb[x] = true;
                if (st[x] && !op[x]) q.push(x);
            }
        }

        return ans;
    }
};

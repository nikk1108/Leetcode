class Solution {
public:
    vector<int> parent, rankv;
    int findp(int x) {
        if (parent[x] != x) parent[x] = findp(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        int pa = findp(a), pb = findp(b);
        if (pa == pb) return;
        if (rankv[pa] < rankv[pb]) {
            parent[pa] = pb;
        } else if (rankv[pb] < rankv[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rankv[pa]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // DSU init
        parent.assign(c+1, 0);
        rankv.assign(c+1, 0);
        for (int i = 1; i <= c; i++) {
            parent[i] = i;
            rankv[i] = 0;
        }
        // build connectivity
        for (auto &conn : connections) {
            int u = conn[0], v = conn[1];
            unite(u, v);
        }

        // map from root → min‐heap (priority_queue) of station IDs in that component
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> compMap;
        for (int i = 1; i <= c; i++) {
            int r = findp(i);
            compMap[r].push(i);
        }

        vector<bool> online(c+1, true);
        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            if (type == 2) {
                // go offline
                online[x] = false;
            } else if (type == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    int r = findp(x);
                    auto &pq = compMap[r];
                    // pop offline ones until top is online or empty
                    while (!pq.empty() && !online[pq.top()]) {
                        pq.pop();
                    }
                    if (pq.empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(pq.top());
                    }
                }
            }
        }
        return ans;
    }
};

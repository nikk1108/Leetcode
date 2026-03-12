class Solution {
public:
    struct DSU {
        vector<int> p, sz;

        DSU(int n) {
            p.resize(n);
            sz.assign(n, 1);
            for (int i = 0; i < n; i++) p[i] = i;
        }

        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]);
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
            return true;
        }
    };

    bool ok(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);
        int used = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (!must) continue;

            if (s < mid) return false;
            if (!dsu.unite(u, v)) return false;
            used++;
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) continue;

            if (s >= mid && dsu.unite(u, v)) {
                used++;
            }
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) continue;

            if (s < mid && 2 * s >= mid && k > 0 && dsu.unite(u, v)) {
                used++;
                k--;
            }
        }

        return used == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 200000, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
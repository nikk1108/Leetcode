#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int budget
    ) {
        vector<vector<int>> graph(n);
        for (auto &e : hierarchy) {
            graph[e[0] - 1].push_back(e[1] - 1);
        }

        map<pair<int,int>, pair<vector<int>, vector<int>>> memo;

        function<pair<vector<int>, vector<int>>(int,int)> solve =
        [&](int node, int parent) -> pair<vector<int>, vector<int>> {

            if (memo.count({node, parent})) return memo[{node, parent}];

            vector<int> base0(budget + 1, 0);
            vector<int> base1(budget + 1, 0);

            for (int nxt : graph[node]) {
                if (nxt == parent) continue;
                auto child = solve(nxt, node);
                base0 = combine(base0, child.first);
                base1 = combine(base1, child.second);
            }

            vector<int> dp0 = base0;
            vector<int> dp1 = base0;

            int costFull = present[node];
            int gainFull = future[node] - costFull;

            for (int b = costFull; b <= budget; b++) {
                dp0[b] = max(dp0[b], base1[b - costFull] + gainFull);
            }

            int costHalf = present[node] / 2;
            int gainHalf = future[node] - costHalf;

            for (int b = costHalf; b <= budget; b++) {
                dp1[b] = max(dp1[b], base1[b - costHalf] + gainHalf);
            }

            return memo[{node, parent}] = {dp0, dp1};
        };

        auto result = solve(0, -1);
        return *max_element(result.first.begin(), result.first.end());
    }

    vector<int> combine(vector<int>& a, vector<int>& b) {
        int sz = a.size();
        vector<int> res(sz, INT_MIN);
        for (int i = 0; i < sz; i++) {
            if (a[i] < 0) continue;
            for (int j = 0; j + i < sz; j++) {
                if (b[j] < 0) continue;
                res[i + j] = max(res[i + j], a[i] + b[j]);
            }
        }
        return res;
    }
};

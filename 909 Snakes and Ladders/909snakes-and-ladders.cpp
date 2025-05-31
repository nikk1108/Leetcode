#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size(), t = n * n;
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> vis;
        vis.insert(1);
        
        while (!q.empty()) {
            auto [x, m] = q.front();
            q.pop();
            if (x == t) return m;
            for (int i = 1; i <= 6; ++i) {
                int nx = x + i;
                if (nx > t) break;
                auto [r, c] = pos(nx, n);
                if (b[r][c] != -1) nx = b[r][c];
                if (!vis.count(nx)) {
                    vis.insert(nx);
                    q.push({nx, m + 1});
                }
            }
        }
        return -1;
    }

private:
    pair<int, int> pos(int x, int n) {
        int r = (x - 1) / n;
        int c = (x - 1) % n;
        if (r % 2) c = n - 1 - c;
        r = n - 1 - r;
        return {r, c};
    }
};


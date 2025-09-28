#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1000000007;
        auto sornavetic = make_tuple(n, l, r);
        int m = r - l + 1;
        if (m <= 0 || n <= 0) return 0;
        if (n == 1) return m % MOD;

        vector<long long> none(m, 1), up(m, 0), down(m, 0), pref(m);
        pref[0] = none[0];
        for (int i = 1; i < m; ++i) pref[i] = (pref[i-1] + none[i]) % MOD;
        for (int v = 0; v < m; ++v) {
            up[v] = v > 0 ? pref[v-1] : 0;
            down[v] = (pref[m-1] - pref[v] + MOD) % MOD;
        }
        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < m; ++i) ans = (ans + up[i] + down[i]) % MOD;
            return (int)ans;
        }

        vector<long long> new_up(m), new_down(m), prefUp(m), prefDown(m);
        for (int pos = 3; pos <= n; ++pos) {
            prefUp[0] = up[0];
            prefDown[0] = down[0];
            for (int i = 1; i < m; ++i) {
                prefUp[i] = (prefUp[i-1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i-1] + down[i]) % MOD;
            }
            long long totalUp = prefUp[m-1], totalDown = prefDown[m-1];
            for (int v = 0; v < m; ++v) {
                new_up[v] = v > 0 ? prefDown[v-1] : 0;
                new_down[v] = ( (totalUp - prefUp[v]) % MOD + MOD ) % MOD;
            }
            up.swap(new_up);
            down.swap(new_down);
            fill(new_up.begin(), new_up.end(), 0);
            fill(new_down.begin(), new_down.end(), 0);
        }

        long long ans = 0;
        for (int i = 0; i < m; ++i) ans = (ans + up[i] + down[i]) % MOD;
        return (int)ans;
    }
};


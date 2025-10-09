#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& alpha, vector<int>& beta) {
        int n = alpha.size(), m = beta.size();
        long long sigma = 0;
        for (int v : alpha) sigma += v;
        long long omega = sigma * 1LL * beta[0];
        for (int j = 1; j < m; ++j) {
            long long phi = omega;
            for (int i = n - 2; i >= 0; --i) {
                phi -= 1LL * alpha[i + 1] * beta[j - 1];
                omega = max(phi, omega - 1LL * alpha[i] * beta[j]);
            }
            omega += sigma * 1LL * beta[j];
        }
        return omega;
    }
};


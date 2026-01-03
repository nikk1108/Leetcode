using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        ll a = 6, b = 6;
        
        for (int i = 1; i < n; ++i) {
            ll na = (a * 3 + b * 2) % MOD;
            ll nb = (a * 2 + b * 2) % MOD;
            a = na;
            b = nb;
        }
        
        return (a + b) % MOD;
    }
};

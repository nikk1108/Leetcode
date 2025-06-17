class Solution {
 public:
  int countGoodArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;
    vector<int> fact(n), inv(n);
    fact[0] = 1;
    for (int i = 1; i < n; ++i)
      fact[i] = 1LL * fact[i - 1] * i % MOD;
    auto powmod = [&](int a, int b) -> int {
      int res = 1;
      while (b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
      }
      return res;
    };
    auto inverse = [&](int x) -> int {
      return powmod(x, MOD - 2);
    };
    inv[n - 1] = inverse(fact[n - 1]);
    for (int i = n - 2; i >= 0; --i)
      inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    auto comb = [&](int a, int b) -> int {
      if (b < 0 || b > a) return 0;
      return int(1LL * fact[a] * inv[b] % MOD * inv[a - b] % MOD);
    };
    return 1LL * m * comb(n - 1, k) % MOD * powmod(m - 1, n - 1 - k) % MOD;
  }
};

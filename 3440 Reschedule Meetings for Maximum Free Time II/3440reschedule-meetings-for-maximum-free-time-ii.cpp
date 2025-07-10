class Solution {
 public:
  int maxFreeTime(int t, vector<int>& s, vector<int>& e) {
    int n = s.size();
    vector<int> g = getGaps(t, s, e);
    int ans = 0;
    vector<int> l(n + 1), r(n + 1);

    l[0] = g[0];
    r[n] = g[n];

    for (int i = 1; i <= n; ++i)
      l[i] = max(g[i], l[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      r[i] = max(g[i], r[i + 1]);

    for (int i = 0; i < n; ++i) {
      int dur = e[i] - s[i];
      int sum = g[i] + g[i + 1];
      bool ok = dur <= max(i > 0 ? l[i - 1] : 0, i + 2 < n + 1 ? r[i + 2] : 0);
      ans = max(ans, sum + (ok ? dur : 0));
    }

    return ans;
  }

 private:
  vector<int> getGaps(int t, const vector<int>& s, const vector<int>& e) {
    vector<int> g{s[0]};
    for (int i = 1; i < s.size(); ++i)
      g.push_back(s[i] - e[i - 1]);
    g.push_back(t - e.back());
    return g;
  }
};

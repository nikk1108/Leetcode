class UnionFind {
 public:
  UnionFind(int n) : p(n), h(n) {
    iota(p.begin(), p.end(), 0);
  }

  void u(int a, int b) {
    int x = f(a);
    int y = f(b);
    if (x == y) return;
    if (h[x] < h[y]) {
      p[x] = y;
    } else if (h[x] > h[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      h[y]++;
    }
  }

  bool c(int a, int b) {
    return f(a) == f(b);
  }

  void rs(int a) {
    p[a] = a;
  }

 private:
  vector<int> p;
  vector<int> h;

  int f(int a) {
    return p[a] == a ? a : p[a] = f(p[a]);
  }
};

class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& m, int fp) {
    vector<int> res;
    UnionFind d(n);
    map<int, vector<pair<int, int>>> mp;

    d.u(0, fp);

    for (auto& v : m)
      mp[v[2]].push_back({v[0], v[1]});

    for (auto& it : mp) {
      unordered_set<int> s;
      for (auto& pr : it.second) {
        d.u(pr.first, pr.second);
        s.insert(pr.first);
        s.insert(pr.second);
      }
      for (int x : s)
        if (!d.c(x, 0))
          d.rs(x);
    }

    for (int i = 0; i < n; i++)
      if (d.c(i, 0))
        res.push_back(i);

    return res;
  }
};

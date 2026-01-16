class RangeTree {
 public:
  explicit RangeTree(const vector<int>& pts)
      : coords(pts), segCount(pts.size() - 1),
        lazy(4 * segCount), length(4 * segCount) {}

  void update(int l, int r, int v) {
    updateNode(0, 0, segCount - 1, l, r, v);
  }

  int query() const {
    return length[0];
  }

 private:
  int segCount;
  vector<int> coords;
  vector<int> lazy;
  vector<int> length;

  void updateNode(int idx, int left, int right, int ql, int qr, int v) {
    if (qr <= coords[left] || coords[right + 1] <= ql)
      return;
    if (ql <= coords[left] && coords[right + 1] <= qr) {
      lazy[idx] += v;
    } else {
      int mid = (left + right) / 2;
      updateNode(idx * 2 + 1, left, mid, ql, qr, v);
      updateNode(idx * 2 + 2, mid + 1, right, ql, qr, v);
    }
    if (lazy[idx] > 0) {
      length[idx] = coords[right + 1] - coords[left];
    } else if (left == right) {
      length[idx] = 0;
    } else {
      length[idx] =
          length[idx * 2 + 1] + length[idx * 2 + 2];
    }
  }
};

class Solution {
 public:
  double separateSquares(vector<vector<int>>& arr) {
    vector<array<int,4>> sweep;
    set<int> uniqX;

    for (auto &e : arr) {
      int px = e[0], py = e[1], sz = e[2];
      sweep.push_back({py, 1, px, px + sz});
      sweep.push_back({py + sz, -1, px, px + sz});
      uniqX.insert(px);
      uniqX.insert(px + sz);
    }

    sort(sweep.begin(), sweep.end());

    double target = computeTotal(sweep, uniqX) / 2.0;
    long long acc = 0;
    int lastY = 0;

    RangeTree st(vector<int>(uniqX.begin(), uniqX.end()));

    for (auto &[cy, d, lx, rx] : sweep) {
      long long cover = st.query();
      long long gain = cover * (long long)(cy - lastY);
      if (acc + gain >= target)
        return lastY + (target - acc) / cover;
      acc += gain;
      st.update(lx, rx, d);
      lastY = cy;
    }

    return 0.0;
  }

 private:
  long long computeTotal(const vector<array<int,4>>& sweep,
                         const set<int>& xs) {
    long long res = 0;
    int last = 0;
    RangeTree st(vector<int>(xs.begin(), xs.end()));
    for (auto &[y, d, l, r] : sweep) {
      res += st.query() * (long long)(y - last);
      st.update(l, r, d);
      last = y;
    }
    return res;
  }
};

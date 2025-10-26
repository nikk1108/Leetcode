class Bank {
 public:
  Bank(vector<long long>& b) : a(move(b)) {}

  bool transfer(int x, int y, long long m) {
    if (!ok(y)) return false;
    return withdraw(x, m) && deposit(y, m);
  }

  bool deposit(int i, long long m) {
    if (!ok(i)) return false;
    a[i - 1] += m;
    return true;
  }

  bool withdraw(int i, long long m) {
    if (!ok(i)) return false;
    if (a[i - 1] < m) return false;
    a[i - 1] -= m;
    return true;
  }

 private:
  vector<long long> a;

  bool ok(int i) {
    return i >= 1 && i <= a.size();
  }
};

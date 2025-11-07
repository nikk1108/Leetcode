class Solution {
 public:
  long long maxPower(vector<int>& arr, int d, int extra) {
    long low = ranges::min(arr);
    long high = accumulate(arr.begin(), arr.end(), 0L) + extra + 1;

    while (low < high) {
      long mid = (low + high) / 2;
      if (ok(arr, d, extra, mid))
        low = mid + 1;
      else
        high = mid;
    }

    return low - 1;
  }

 private:
  bool ok(vector<int> arr, int d, int left, long target) {
    int n = arr.size();
    long cur = accumulate(arr.begin(), arr.begin() + d, 0L);

    for (int i = 0; i < n; ++i) {
      if (i + d < n) cur += arr[i + d];
      if (cur < target) {
        long need = target - cur;
        if (need > left) return false;
        arr[min(n - 1, i + d)] += need;
        left -= need;
        cur += need;
      }
      if (i - d >= 0) cur -= arr[i - d];
    }

    return true;
  }
};

class Solution {
 public:
  int maxSum(vector<int>& arr) {
    const int highest = ranges::max(arr);
    if (highest <= 0)
      return highest;
    unordered_set<int> uniqueVals(arr.begin(), arr.end());
    return accumulate(uniqueVals.begin(), uniqueVals.end(), 0,
                      [](int sum, int val) { return sum + max(0, val); });
  }
};


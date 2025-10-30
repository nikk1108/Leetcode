class Solution {
 public:
  int minNumberOperations(vector<int>& arr) {
    int res = arr[0];
    for (int i = 1; i < arr.size(); ++i)
      if (arr[i] > arr[i - 1])
        res += arr[i] - arr[i - 1];
    return res;
  }
};

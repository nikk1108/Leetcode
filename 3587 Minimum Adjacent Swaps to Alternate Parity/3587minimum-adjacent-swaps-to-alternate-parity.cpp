class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    vector<int> evenIdx, oddIdx;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0)
        evenIdx.push_back(i);
      else
        oddIdx.push_back(i);
    }

    int n = nums.size();
    if (abs(int(evenIdx.size()) - int(oddIdx.size())) > 1)
      return -1;

    if (evenIdx.size() > oddIdx.size())
      return getSwaps(evenIdx, 0);
    if (oddIdx.size() > evenIdx.size())
      return getSwaps(oddIdx, 0);

    return min(getSwaps(evenIdx, 0), getSwaps(oddIdx, 0));
  }

 private:
  int getSwaps(const vector<int>& indices, int start) {
    int swaps = 0;
    for (int i = 0; i < indices.size(); ++i)
      swaps += abs(indices[i] - (start + 2 * i));
    return swaps;
  }
};

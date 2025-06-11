class Solution {
 public:
  int maxDifference(string s, int k) {
    int maxDiff = INT_MIN;

    for (const auto& [ch1, ch2] : getCharPairs()) {
      vector<vector<int>> minVal(2, vector<int>(2, INT_MAX / 2));
      vector<int> count1{0};
      vector<int> count2{0};

      for (int left = 0, right = 0; right < s.length(); ++right) {
        count1.push_back(count1.back() + (s[right] == ch1 ? 1 : 0));
        count2.push_back(count2.back() + (s[right] == ch2 ? 1 : 0));

        while (right - left + 1 >= k &&
               count1[left] < count1.back() &&
               count2[left] < count2.back()) {
          minVal[count1[left] % 2][count2[left] % 2] =
              min(minVal[count1[left] % 2][count2[left] % 2],
                  count1[left] - count2[left]);
          ++left;
        }

        maxDiff = max(maxDiff,
                      (count1.back() - count2.back()) -
                          minVal[1 - count1.back() % 2][count2.back() % 2]);
      }
    }

    return maxDiff;
  }

 private:
  vector<pair<char, char>> getCharPairs() {
    vector<pair<char, char>> result;
    for (char x : "01234")
      for (char y : "01234")
        if (x != y)
          result.emplace_back(x, y);
    return result;
  }
};


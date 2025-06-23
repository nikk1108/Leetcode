class Solution {
 public:
  long long kMirror(int k, int n) {
    long long sum = 0;
    int count = 0;
    int length = 1;

    while (count < n) {
      vector<string> palindromes = generatePalindromes(length);
      for (const string& p : palindromes) {
        long long num = stoll(p);
        if (isPalindrome(toBase(num, k))) {
          sum += num;
          if (++count == n)
            return sum;
        }
      }
      ++length;
    }

    return sum;
  }

 private:
  // Generate all palindromes of given length
  vector<string> generatePalindromes(int length) {
    vector<string> result;

    int halfLen = (length + 1) / 2;
    int start = (length == 1) ? 1 : pow(10, halfLen - 1);
    int end = pow(10, halfLen);

    for (int i = start; i < end; ++i) {
      string half = to_string(i);
      string full = half;
      if (length % 2 == 1)
        full.pop_back();
      reverse(half.begin(), half.end());
      full += half;
      result.push_back(full);
    }

    return result;
  }

  // Convert number to base-k as a string
  string toBase(long long num, int base) {
    string res;
    while (num > 0) {
      res += '0' + (num % base);
      num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  // Check if a string is a palindrome
  bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l++] != s[r--])
        return false;
    }
    return true;
  }
};

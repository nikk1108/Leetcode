class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.size();

        for (char c = 'a'; c <= 'z'; c++) {
            int l = -1, r = -1;

            for (int i = 0; i < n; i++)
                if (s[i] == c) { l = i; break; }

            for (int i = n - 1; i >= 0; i--)
                if (s[i] == c) { r = i; break; }

            if (l != -1 && r != -1 && r - l > 1) {
                bool seen[26] = {};
                for (int i = l + 1; i < r; i++)
                    seen[s[i] - 'a'] = true;

                ans += count(seen, seen + 26, true);
            }
        }

        return ans;
    }
};

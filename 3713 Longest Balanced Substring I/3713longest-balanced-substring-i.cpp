class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int mn = 1000000000;
                int mx = 0;

                for (int c = 0; c < 26; ++c) {
                    if (freq[c] > 0) {
                        mn = min(mn, freq[c]);
                        mx = max(mx, freq[c]);
                    }
                }

                if (mn == mx) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();

        for (int z = 0; z + z * z <= n; ++z) {
            int lastBad = -1;
            vector<int> cnt(2, 0);

            for (int l = 0, r = 0; r < n; ++r) {
                cnt[s[r] - '0']++;

                for (; l < r; ++l) {
                    if (s[l] == '0' && cnt[0] > z) {
                        cnt[0]--;
                        lastBad = l;
                    } else if (s[l] == '1' && cnt[1] - 1 >= z * z) {
                        cnt[1]--;
                    } else {
                        break;
                    }
                }

                if (cnt[0] == z && cnt[1] >= z * z)
                    ans += l - lastBad;
            }
        }

        return ans;
    }
};

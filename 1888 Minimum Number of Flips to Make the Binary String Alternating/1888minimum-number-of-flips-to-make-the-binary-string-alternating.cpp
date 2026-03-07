class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;
        int a = 0, b = 0, ans = n;

        for (int i = 0; i < 2 * n; i++) {
            if (t[i] != (i % 2 ? '1' : '0')) a++;
            if (t[i] != (i % 2 ? '0' : '1')) b++;

            if (i >= n) {
                if (t[i - n] != ((i - n) % 2 ? '1' : '0')) a--;
                if (t[i - n] != ((i - n) % 2 ? '0' : '1')) b--;
            }

            if (i >= n - 1) ans = min(ans, min(a, b));
        }
        return ans;
    }
};
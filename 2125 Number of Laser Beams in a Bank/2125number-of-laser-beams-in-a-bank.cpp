class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        int p = 0, ans = 0;
        for (auto& s : b) {
            int c = count(s.begin(), s.end(), '1');
            if (c) ans += p * c, p = c;
        }
        return ans;
    }
};

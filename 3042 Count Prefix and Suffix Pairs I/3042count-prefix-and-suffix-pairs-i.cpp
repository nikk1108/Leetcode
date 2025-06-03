class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& w) {
        int cnt = 0, n = w.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                const string& s = w[j], &t = w[i];
                int len = s.size();
                if (t.substr(0, len) == s && t.substr(t.size() - len) == s)
                    ++cnt;
            }
        }
        return cnt;
    }
};

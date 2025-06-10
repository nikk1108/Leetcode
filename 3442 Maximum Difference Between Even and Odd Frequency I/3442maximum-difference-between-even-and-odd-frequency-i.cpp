class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        int o = INT_MIN, e = INT_MAX;
        for (auto& [c, f] : m) {
            if (f % 2) o = max(o, f);
            else e = min(e, f);
        }
        return o - e;
    }
};

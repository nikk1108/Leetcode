class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;

    bool solve(string curr, string next, int i) {
        if (next.empty() && bad.count(curr)) return false;
        if (curr.size() == 1) return true;

        if (next.size() == curr.size() - 1) {
            bool ok = solve(next, "", 0);
            if (!ok) bad.insert(curr);
            return ok;
        }

        string key = curr.substr(i, 2);
        if (!mp.count(key)) return false;

        for (char c : mp[key]) {
            if (solve(curr, next + c, i + 1))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string s : allowed)
            mp[s.substr(0, 2)].push_back(s[2]);

        return solve(bottom, "", 0);
    }
};

class Solution {
public:
    void dfs(int n, string &cur, vector<string> &res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }

        for (char c : {'a','b','c'}) {
            if (!cur.empty() && cur.back() == c) continue;
            cur.push_back(c);
            dfs(n, cur, res);
            cur.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        string cur;
        dfs(n, cur, res);

        if (k > res.size()) return "";
        return res[k-1];
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int ops) {
        int res = 1, cur = 0;
        unordered_map<int, int> cnt;
        map<int, int> diff;
        set<int> s;

        for (int x : a) {
            ++cnt[x];
            ++diff[x - k];
            --diff[x + k + 1];
            s.insert(x);
            s.insert(x - k);
            s.insert(x + k + 1);
        }

        for (int x : s) {
            cur += diff.contains(x) ? diff[x] : 0;
            int c = cnt.contains(x) ? cnt[x] : 0;
            int adj = cur - c;
            res = max(res, c + min(ops, adj));
        }

        return res;
    }
};

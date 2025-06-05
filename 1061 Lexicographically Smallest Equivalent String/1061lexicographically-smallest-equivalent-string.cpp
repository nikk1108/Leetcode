class Solution {
public:
    int f(vector<int>& p, int x) {
        if (p[x] != x) p[x] = f(p, p[x]);
        return p[x];
    }

    void u(vector<int>& p, int x, int y) {
        int px = f(p, x), py = f(p, y);
        if (px == py) return;
        if (px < py) p[py] = px;
        else p[px] = py;
    }

    string smallestEquivalentString(string a, string b, string s) {
        vector<int> p(26);
        for (int i = 0; i < 26; ++i) p[i] = i;
        for (int i = 0; i < a.size(); ++i) u(p, a[i] - 'a', b[i] - 'a');
        string r;
        for (char c : s) r += (char)(f(p, c - 'a') + 'a');
        return r;
    }
};

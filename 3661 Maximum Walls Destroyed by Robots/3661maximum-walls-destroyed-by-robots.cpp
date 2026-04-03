class Solution {
public:
    int maxWalls(vector<int>& a, vector<int>& b, vector<int>& w) {
        int n = a.size();

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[a[i]] = b[i];

        sort(a.begin(), a.end());
        sort(w.begin(), w.end());

        vector<int> L(n), R(n), mid(n);

        for(int i = 0; i < n; i++) {
            int x = a[i];
            int d = mp[x];

            int up = upper_bound(w.begin(), w.end(), x) - w.begin();
            int lo;

            if(i > 0) {
                lo = lower_bound(w.begin(), w.end(), max(x - d, a[i-1] + 1)) - w.begin();
            } else {
                lo = lower_bound(w.begin(), w.end(), x - d) - w.begin();
            }

            L[i] = up - lo;

            int hi;
            if(i < n - 1) {
                hi = upper_bound(w.begin(), w.end(), min(x + d, a[i+1] - 1)) - w.begin();
            } else {
                hi = upper_bound(w.begin(), w.end(), x + d) - w.begin();
            }

            int st = lower_bound(w.begin(), w.end(), x) - w.begin();
            R[i] = hi - st;

            if(i > 0) {
                int p = lower_bound(w.begin(), w.end(), a[i-1]) - w.begin();
                mid[i] = up - p;
            }
        }

        int l = L[0], r = R[0];

        for(int i = 1; i < n; i++) {
            int nl = max(l + L[i], r - R[i-1] + min(L[i] + R[i-1], mid[i]));
            int nr = max(l + R[i], r + R[i]);
            l = nl;
            r = nr;
        }

        return max(l, r);
    }
};
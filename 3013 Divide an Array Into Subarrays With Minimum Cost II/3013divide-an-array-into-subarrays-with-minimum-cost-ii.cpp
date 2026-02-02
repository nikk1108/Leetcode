class Solution {
public:
    long long minimumCost(vector<int>& a, int k, int d) {
        multiset<int> s1, s2;
        long cur = 0;

        for (int i = 1; i <= d + 1; i++) {
            cur += a[i];
            s1.insert(a[i]);
        }

        cur = fix(cur, s1, s2, k);
        long best = cur;

        for (int i = d + 2; i < a.size(); i++) {
            int rem = a[i - d - 1];

            auto it1 = s1.find(rem);
            if (it1 != s1.end()) {
                cur -= rem;
                s1.erase(it1);
            } else {
                s2.erase(s2.find(rem));
            }

            if (!s1.empty() && a[i] < *s1.rbegin()) {
                cur += a[i];
                s1.insert(a[i]);
            } else {
                s2.insert(a[i]);
            }

            cur = fix(cur, s1, s2, k);
            best = min(best, cur);
        }

        return a[0] + best;
    }

private:
    long fix(long sum, multiset<int>& x, multiset<int>& y, int k) {
        while (x.size() < k - 1) {
            int v = *y.begin();
            sum += v;
            x.insert(v);
            y.erase(y.begin());
        }

        while (x.size() > k - 1) {
            int v = *x.rbegin();
            sum -= v;
            x.erase(--x.end());
            y.insert(v);
        }

        return sum;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(), ops = 0, bad = 0;
        vector<long long> a(nums.begin(), nums.end());
        vector<int> l(n), r(n);

        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            r[i] = i + 1;
            if (i + 1 < n && nums[i] > nums[i + 1]) bad++;
        }

        auto cmp = [](const pair<long long,int>& x, const pair<long long,int>& y) {
            if (x.first != y.first) return x.first < y.first;
            return x.second < y.second;
        };

        set<pair<long long,int>, decltype(cmp)> st(cmp);

        for (int i = 0; i + 1 < n; i++)
            st.insert({a[i] + a[i + 1], i});

        while (bad > 0) {
            ops++;
            auto it = st.begin();
            long long sum = it->first;
            int i = it->second;
            st.erase(it);

            int j = r[i];
            int li = l[i];

            if (li >= 0) {
                st.erase({a[li] + a[i], li});
                if (a[li] > a[i]) bad--;
                if (a[li] > sum) bad++;
                st.insert({a[li] + sum, li});
            }

            if (a[j] < a[i]) bad--;

            int nj = r[j];
            if (nj < n) {
                st.erase({a[j] + a[nj], j});
                if (a[nj] < a[j]) bad--;
                if (a[nj] < sum) bad++;
                st.insert({sum + a[nj], i});
                l[nj] = i;
            }

            r[i] = nj;
            a[i] = sum;
        }

        return ops;
    }
};

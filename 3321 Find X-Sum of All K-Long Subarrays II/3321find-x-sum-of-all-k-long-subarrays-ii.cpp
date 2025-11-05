class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using P = pair<int, int>;
        set<P> a, b;
        long long sum = 0;
        unordered_map<int, int> f;

        auto add = [&](int v) {
            if (f[v] == 0) return;
            P p = {f[v], v};
            if (!a.empty() && p > *a.begin()) {
                sum += 1LL * p.first * p.second;
                a.insert(p);
            } else {
                b.insert(p);
            }
        };

        auto rem = [&](int v) {
            if (f[v] == 0) return;
            P p = {f[v], v};
            auto it = a.find(p);
            if (it != a.end()) {
                sum -= 1LL * p.first * p.second;
                a.erase(it);
            } else {
                b.erase(p);
            }
        };

        vector<long long> ans;

        for (int i = 0; i < nums.size(); ++i) {
            rem(nums[i]);
            ++f[nums[i]];
            add(nums[i]);

            int s = i - k + 1;
            if (s < 0) continue;

            while (!b.empty() && a.size() < x) {
                P p = *b.rbegin();
                sum += 1LL * p.first * p.second;
                b.erase(p);
                a.insert(p);
            }

            while (a.size() > x) {
                P p = *a.begin();
                sum -= 1LL * p.first * p.second;
                a.erase(p);
                b.insert(p);
            }

            ans.push_back(sum);

            rem(nums[s]);
            --f[nums[s]];
            add(nums[s]);
        }

        return ans;
    }
};

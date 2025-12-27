class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> FR;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> BR;

        for (int i = 0; i < n; i++) FR.push(i);

        vector<int> cnt(n, 0);

        for (auto &m : meetings) {
            long long s = m[0], e = m[1];
            long long d = e - s;

            while (!BR.empty() && BR.top().first <= s) {
                FR.push(BR.top().second);
                BR.pop();
            }

            if (!FR.empty()) {
                int r = FR.top();
                FR.pop();
                cnt[r]++;
                BR.push({e, r});
            } else {
                auto x = BR.top();
                BR.pop();
                cnt[x.second]++;
                BR.push({x.first + d, x.second});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans]) ans = i;
        }
        return ans;
    }
};

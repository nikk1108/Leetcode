class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        const long long MOD = 1000000007;
        
        hf.push_back(1);
        hf.push_back(m);
        vf.push_back(1);
        vf.push_back(n);
        
        sort(hf.begin(), hf.end());
        sort(vf.begin(), vf.end());
        
        unordered_set<long long> hs;
        int x = hf.size();
        int y = vf.size();
        
        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {
                hs.insert((long long)hf[j] - hf[i]);
            }
        }
        
        long long ans = -1;
        for (int i = 0; i < y; i++) {
            for (int j = i + 1; j < y; j++) {
                long long d = (long long)vf[j] - vf[i];
                if (hs.count(d)) {
                    ans = max(ans, d * d);
                }
            }
        }
        
        if (ans == -1) return -1;
        return ans % MOD;
    }
};

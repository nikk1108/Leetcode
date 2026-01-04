class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int s = 0, c = 0;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int e = x / d;
                    if (d == e) {
                        c++;
                        s += d;
                    } else {
                        c += 2;
                        s += d + e;
                    }
                }
                if (c > 4) break;
            }
            if (c == 4) ans += s;
        }
        return ans;
    }
};

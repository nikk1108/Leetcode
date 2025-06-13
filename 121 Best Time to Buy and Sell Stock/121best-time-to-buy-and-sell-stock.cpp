class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mn = p[0], res = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] < mn) mn = p[i];
            else if (p[i] - mn > res) res = p[i] - mn;
        }
        return res;
    }
};


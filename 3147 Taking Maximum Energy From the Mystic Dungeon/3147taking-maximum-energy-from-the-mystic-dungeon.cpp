#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& val, int gap) {
        int sz = val.size();
        vector<int> buf(sz);
        int ans = INT_MIN;
        for(int idx = sz - 1; idx >= 0; --idx) {
            if(idx + gap < sz) buf[idx] = val[idx] + buf[idx + gap];
            else buf[idx] = val[idx];
            ans = max(ans, buf[idx]);
        }
        return ans;
    }
};

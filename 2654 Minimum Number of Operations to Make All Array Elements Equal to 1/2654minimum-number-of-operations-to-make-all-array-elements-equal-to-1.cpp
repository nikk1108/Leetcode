#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(), nums.end(), 1);
        
        if (cnt1 > 0) 
            return n - cnt1;  // already have some 1's
        
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans + n - 1;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& pts) {
        int res = 0;

        sort(pts.begin(), pts.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        for (int i = 0; i < pts.size(); i++) {
            int best = INT_MIN;
            for (int j = i + 1; j < pts.size(); j++) {
                if (pts[i][1] >= pts[j][1] && pts[j][1] > best) {
                    res++;
                    best = pts[j][1];
                }
            }
        }
        return res;
    }
};

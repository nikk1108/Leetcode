#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int best = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] <= points[i][1] && points[j][1] > best) {
                    res++;
                    best = points[j][1];
                }
            }
        }
        return res;
    }
};

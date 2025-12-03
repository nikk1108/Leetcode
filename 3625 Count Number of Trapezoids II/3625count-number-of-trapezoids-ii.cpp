class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<double, unordered_map<double, int>> slopeInterceptCount;
        unordered_map<int, unordered_map<double, int>> midpointSlopeCount;

        slopeInterceptCount.reserve(n * n);
        midpointSlopeCount.reserve(n * n);

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = 0; j < i; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                double slope = (dx == 0 ? 1e9 : (double)dy / dx);
                double intercept = (dx == 0 ? x1 :
                    (double)(1LL * y1 * dx - 1LL * x1 * dy) / dx);

                slopeInterceptCount[slope][intercept]++;

                int midHash = (x1 + x2 + 2000) * 4000 + (y1 + y2 + 2000);
                midpointSlopeCount[midHash][slope]++;
            }
        }

        int result = 0;

        for (auto& [slope, interceptMap] : slopeInterceptCount) {
            int prefix = 0;
            for (auto& [intercept, count] : interceptMap) {
                result += prefix * count;
                prefix += count;
            }
        }

        for (auto& [midHash, slopeMap] : midpointSlopeCount) {
            int prefix = 0;
            for (auto& [slope, count] : slopeMap) {
                result -= prefix * count;
                prefix += count;
            }
        }

        return result;
    }
};

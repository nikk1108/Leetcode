class Solution {
    public:
        double separateSquares(vector<vector<int>>& squares) {
                double total = 0;
                        double hi = 0;
                                for (auto &s : squares) {
                                            total += 1.0 * s[2] * s[2];
                                                        hi = max(hi, s[1] + s[2] * 1.0);
                                                                }
                                                                        double target = total / 2.0;
                                                                                double lo = 0.0;
                                                                                        auto area = [&](double h) {
                                                                                                    double a = 0.0;
                                                                                                                for (auto &s : squares) {
                                                                                                                                if (h > s[1]) {
                                                                                                                                                    double t = min(h - s[1], (double)s[2]);
                                                                                                                                                                        a += t * s[2];
                                                                                                                                                                                        }
                                                                                                                                                                                                    }
                                                                                                                                                                                                                return a;
                                                                                                                                                                                                                        };
                                                                                                                                                                                                                                while (hi - lo > 1e-5) {
                                                                                                                                                                                                                                            double mid = (lo + hi) / 2.0;
                                                                                                                                                                                                                                                        if (area(mid) < target) lo = mid;
                                                                                                                                                                                                                                                                    else hi = mid;
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                    return hi;
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                        };
                                                                                                                                                                                                                                                                                        

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        int res = 0;
        int x = -1;
        int y = -1;

        ranges::sort(a, ranges::less{}, [](const vector<int>& v) {
            return pair<int,int>{v[1], -v[0]};
        });

        for (const auto& v : a) {
            int l = v[0];
            int r = v[1];

            if (x >= l && y >= l)
                continue;

            if (x >= l) {
                y = x;
                x = r;
                res++;
            } else {
                x = r;
                y = r - 1;
                res += 2;
            }
        }

        return res;
    }
};

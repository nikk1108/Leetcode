class Solution {
public:
    long long distributeCandies(int c, int l) {
        auto comb2 = [](int x) -> long long {
            return static_cast<long long>(x) * (x - 1) / 2;
        };

        if (c > 3 * l) return 0;

        long long res = comb2(c + 2);

        if (c > l) res -= 3 * comb2(c - l + 1);

        if (c - 2 >= 2 * l) res += 3 * comb2(c - 2 * l);

        return res;
    }
};


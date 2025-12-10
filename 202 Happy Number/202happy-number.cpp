class Solution {
public:
    bool isHappy(int n) {
         unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = sumSq(n);
        }

        return n == 1;
    }

    int sumSq(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
};
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            int a = n & 1;
            int b = (n >> 1) & 1;
            if (a == b) return false;
            n >>= 1;
        }
        return true;
    }
};

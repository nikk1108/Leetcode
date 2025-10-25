class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int first = sum(1, 7);
        int last = sum(w, w + 6);
        int rem = sum(w + 1, w + n % 7);
        return (first + last) * w / 2 + rem;
    }

    int sum(int a, int b) {
        return (a + b) * (b - a + 1) / 2;
    }
};

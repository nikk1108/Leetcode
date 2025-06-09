class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;  // first number is 1, so we start from there

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Move to next prefix
                curr += 1;
                k -= steps;
            } else {
                // Go deeper into this prefix
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }

private:
    long long countSteps(int n, long long first, long long last) {
        long long steps = 0;
        while (first <= n) {
            steps += min((long long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }
};

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> group;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            ++group[sum];
            maxSize = max(maxSize, group[sum]);
        }

        int count = 0;
        for (auto& [_, size] : group) {
            if (size == maxSize)
                ++count;
        }
        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;
        for (int x : nums) count[(x % value + value) % value]++;
        for (int i = 0;; i++) {
            int r = i % value;
            if (count[r] == 0) return i;
            count[r]--;
        }
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c = 0;
        for (int x : nums) {
            int d = 0;
            while (x > 0) {
                d++;
                x /= 10;
            }
            if (d % 2 == 0) c++;
        }
        return c;
    }
};

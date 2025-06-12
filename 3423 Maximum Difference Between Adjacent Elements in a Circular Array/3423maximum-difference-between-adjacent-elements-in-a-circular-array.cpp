#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n; // Circular array
            maxDiff = max(maxDiff, abs(nums[i] - nums[next]));
        }

        return maxDiff;
    }
};

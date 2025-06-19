#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;  // At least one subsequence is needed
        int start = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - start > k) {
                count++;
                start = nums[i];  // Start new subsequence
            }
        }

        return count;
    }
};

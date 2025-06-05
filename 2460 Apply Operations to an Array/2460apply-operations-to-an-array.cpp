class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Apply operations
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        vector<int> res(n, 0);
        int idx = 0;
        for (int num : nums) {
            if (num != 0) {
                res[idx++] = num;
            }
        }

        return res;
    }
};

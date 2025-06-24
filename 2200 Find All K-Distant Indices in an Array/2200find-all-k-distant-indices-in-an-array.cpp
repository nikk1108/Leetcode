class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> resultSet;
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    resultSet.insert(i);
                }
            }
        }

        vector<int> result(resultSet.begin(), resultSet.end());
        sort(result.begin(), result.end()); // sort in increasing order
        return result;
    }
};

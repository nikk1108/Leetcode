class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
            } else {
                int mask = 1;
                while (num & mask) mask <<= 1;
                ans.push_back(num - (mask >> 1));
            }
        }
        return ans;
    }
};

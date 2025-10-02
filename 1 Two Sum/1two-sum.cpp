class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a[i] + a[j] == t) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

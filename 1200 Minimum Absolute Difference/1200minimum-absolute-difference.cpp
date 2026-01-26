class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int d = arr[1] - arr[0];
        vector<vector<int>> ans;

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];

            if (diff < d) {
                d = diff;
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }
            else if (diff == d) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};

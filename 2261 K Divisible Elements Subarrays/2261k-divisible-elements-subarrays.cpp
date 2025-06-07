#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> subarrays;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int count = 0;
            vector<int> temp;

            for (int j = i; j < n; ++j) {
                temp.push_back(nums[j]);
                if (nums[j] % p == 0) count++;

                if (count > k) break;
                subarrays.insert(temp);
            }
        }

        return subarrays.size();
    }
};

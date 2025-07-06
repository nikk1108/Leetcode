#include <unordered_map>
#include <vector>
using namespace std;

class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums2) {
            freq[num]++;
        }
    }

    void add(int index, int val) {
        freq[nums2[index]]--;         // Decrease count of old value
        nums2[index] += val;
        freq[nums2[index]]++;         // Increase count of new value
    }

    int count(int tot) {
        int res = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freq.count(complement)) {
                res += freq[complement];
            }
        }
        return res;
    }
};

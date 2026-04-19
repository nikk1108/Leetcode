class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i = 0; i < n1; ++i) {
            int value = nums1[i];

            int left = i;
            int right = n2 - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] < value) {  
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

        
            int lastValidJ;
            if (firstTrueIndex == -1) {
                
                lastValidJ = n2 - 1;
            } else {
               
                lastValidJ = firstTrueIndex - 1;
            }

            if (lastValidJ >= i) {
                maxDist = max(maxDist, lastValidJ - i);
            }
        }

        return maxDist;
    }
};
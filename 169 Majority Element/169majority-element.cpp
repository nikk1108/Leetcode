class Solution {
public:
    int majorityElement(vector<int>& a) {
        int count = 0, cand = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (count == 0) cand = a[i];
            count += (a[i] == cand) ? 1 : -1;
        }
        return cand;
    }
};

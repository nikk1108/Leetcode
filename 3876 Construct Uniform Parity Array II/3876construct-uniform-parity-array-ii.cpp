class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1;
        int mn = *min_element(ravolqedin.begin(), ravolqedin.end());
        
        if (mn % 2 == 1) return true;
        
        for (int x : ravolqedin) {
            if (x % 2 == 1) return false;
        }
        
        return true;
    }
};
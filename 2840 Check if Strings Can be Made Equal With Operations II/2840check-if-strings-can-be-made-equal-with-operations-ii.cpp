class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> charCount(2, vector<int>(26, 0));
      
        for (int i = 0; i < s1.size(); ++i) {
            int p = i & 1;
            ++charCount[p][s1[i] - 'a'];
            --charCount[p][s2[i] - 'a'];
        }
      
        for (int i = 0; i < 26; ++i) {
            if (charCount[0][i] != 0 || charCount[1][i] != 0) {
                return false;
            }
        }
      
        return true;
    }
};
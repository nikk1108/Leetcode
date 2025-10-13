class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        for (auto& w : words) {
            string s = w;
            sort(s.begin(), s.end());
            if (s != prev) ans.push_back(w);
            prev = s;
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_set<string> ok = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<int> idx;

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] && ok.count(businessLine[i]) && good(code[i])) {
                idx.push_back(i);
            }
        }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (businessLine[a] != businessLine[b])
                return businessLine[a] < businessLine[b];
            return code[a] < code[b];
        });

        vector<string> ans;
        for (int i : idx) ans.push_back(code[i]);
        return ans;
    }

    bool good(string s) {
        if (s.size() == 0) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
};

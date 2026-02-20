class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int bal = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            bal += (s[i] == '1' ? 1 : -1);
            if (bal == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        sort(parts.rbegin(), parts.rend());
        string ans;
        for (auto &p : parts) ans += p;
        return ans;
    }
};
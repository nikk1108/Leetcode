class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');
        string left = p.substr(0, star);
        string right = p.substr(star + 1);
        int minLen = left.size() + right.size();

        for (int i = 0; i + minLen <= s.size(); ++i) {
            int maxLen = s.size() - i;
            for (int len = minLen; len <= maxLen; ++len) {
                string sub = s.substr(i, len);
                if (sub.starts_with(left) && sub.ends_with(right))
                    return true;
            }
        }
        return false;
    }
};

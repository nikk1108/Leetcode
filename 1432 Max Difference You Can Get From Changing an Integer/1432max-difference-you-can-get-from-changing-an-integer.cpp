class Solution {
public:
    int maxDiff(int n) {
        string s = to_string(n), a = s, b = s;

        for (char c : s) {
            if (c != '9') {
                for (char &x : a)
                    if (x == c) x = '9';
                break;
            }
        }

        if (s[0] != '1') {
            char c = s[0];
            for (char &x : b)
                if (x == c) x = '1';
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char c = s[i];
                    for (char &x : b)
                        if (x == c) x = '0';
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};

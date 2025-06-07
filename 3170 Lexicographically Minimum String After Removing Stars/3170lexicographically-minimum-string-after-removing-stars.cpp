class Solution {
public:
    string clearStars(string s) {
        vector<int> pos[26];
        int n = s.size();
        vector<bool> skip(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                skip[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!pos[j].empty()) {
                        skip[pos[j].back()] = true;
                        pos[j].pop_back();
                        break;
                    }
                }
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }

        string res;
        for (int i = 0; i < n; ++i)
            if (!skip[i]) res += s[i];
        return res;
    }
};


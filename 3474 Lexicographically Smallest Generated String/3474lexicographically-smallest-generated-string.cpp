class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int L = n + m - 1;
        string w(L, '?');

        for (int i = 0; i < n; i++) {
            if (s1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (w[i + j] == '?' || w[i + j] == s2[j])
                        w[i + j] = s2[j];
                    else
                        return "";
                }
            }
        }

        for (int i = 0; i < L; i++) {
            if (w[i] == '?') w[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (s1[i] == 'F') {
                bool ok = true;
                for (int j = 0; j < m; j++) {
                    if (w[i + j] != s2[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    bool changed = false;
                    for (int j = m - 1; j >= 0; j--) {
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != w[i + j]) {
                                char old = w[i + j];
                                w[i + j] = c;

                                bool good = true;
                                for (int k = 0; k < n; k++) {
                                    if (s1[k] == 'T') {
                                        for (int x = 0; x < m; x++) {
                                            if (w[k + x] != s2[x]) {
                                                good = false;
                                                break;
                                            }
                                        }
                                    }
                                    if (!good) break;
                                }

                                if (good) {
                                    changed = true;
                                    break;
                                }
                                w[i + j] = old;
                            }
                        }
                        if (changed) break;
                    }
                    if (!changed) return "";
                }
            }
        }

        return w;
    }
};
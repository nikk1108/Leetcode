class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            char e0 = (i % 2 == 0) ? '0' : '1';
            if (s[i] != e0) a++;
            else b++;
        }
        return min(a, b);
    }
};
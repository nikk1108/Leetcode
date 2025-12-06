class Solution {
public:
    bool prime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i*i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = pre*10 + (s[i]-'0');
            if (!prime(pre)) return false;
        }

        int suf = 0, p = 1;
        for (int i = n-1; i >= 0; i--) {
            suf += (s[i]-'0') * p;  
            p *= 10;
            if (!prime(suf)) return false;
        }

        return true;
    }
};

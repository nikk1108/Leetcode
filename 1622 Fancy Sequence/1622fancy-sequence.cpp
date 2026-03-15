class Fancy {
public:
    void append(int v) {
        long t = (v - add + MOD) % MOD;
        arr.push_back((t * power(mult, MOD - 2)) % MOD);
    }

    void addAll(int x) {
        add = (add + x) % MOD;
    }

    void multAll(int m) {
        mult = (mult * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int i) {
        if (i >= arr.size()) return -1;
        return (mult * arr[i] + add) % MOD;
    }

private:
    static const int MOD = 1000000007;
    vector<unsigned long long> arr;
    unsigned long long mult = 1, add = 0;

    long power(long a, long b) {
        if (b == 0) return 1;
        if (b & 1) return (a * power(a % MOD, b - 1)) % MOD;
        return power((a * a) % MOD, b / 2) % MOD;
    }
};
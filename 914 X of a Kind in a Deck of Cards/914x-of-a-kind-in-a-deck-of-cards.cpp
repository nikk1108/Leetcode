class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) freq[card]++;

        int gcdVal = 0;
        for (auto& [key, count] : freq)
            gcdVal = gcd(gcdVal, count);

        return gcdVal >= 2;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

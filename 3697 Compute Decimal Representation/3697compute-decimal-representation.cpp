class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> parts;
        int position = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit) {
                int component = digit;
                for (int i = 0; i < position; i++) component *= 10;
                parts.push_back(component);
            }
            n /= 10;
            position++;
        }
        sort(parts.rbegin(), parts.rend());
        return parts;
    }
};

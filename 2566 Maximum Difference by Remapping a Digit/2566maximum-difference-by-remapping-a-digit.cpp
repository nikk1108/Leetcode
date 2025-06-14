class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = num, minVal = num;

        for (char d1 = '0'; d1 <= '9'; ++d1) {
            for (char d2 = '0'; d2 <= '9'; ++d2) {
                if (d1 == d2) continue;
                string temp = s;
                for (char& c : temp) {
                    if (c == d1) c = d2;
                }
                int val = stoi(temp);
                maxVal = max(maxVal, val);
                minVal = min(minVal, val);
            }
        }

        return maxVal - minVal;
    }
};

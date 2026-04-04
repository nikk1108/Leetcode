class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        if (n == 0) return "";
        
        int cols = n / rows;
        string ans;
        
        for (int st = 0; st < cols; st++) {
            int i = 0, j = st;
            while (i < rows && j < cols) {
                ans += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
        
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
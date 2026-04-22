class Solution {
public:
    bool isValid(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (string &q : queries) {
            for (string &d : dictionary) {
                if (isValid(q, d)) {
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};
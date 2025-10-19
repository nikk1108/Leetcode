class Solution {
public:
    string findLexSmallestString(string str, int addVal, int rotVal) {
        int n = str.size();
        unordered_set<string> seen;
        queue<string> que;
        que.push(str);
        seen.insert(str);
        string result = str;
        while (!que.empty()) {
            string curr = que.front(); que.pop();
            result = min(result, curr);
            string t1 = curr;
            for (int i = 1; i < n; i += 2) {
                t1[i] = char('0' + (t1[i] - '0' + addVal) % 10);
            }
            if (!seen.count(t1)) {
                seen.insert(t1);
                que.push(t1);
            }
            string t2 = curr.substr(n - rotVal) + curr.substr(0, n - rotVal);
            if (!seen.count(t2)) {
                seen.insert(t2);
                que.push(t2);
            }
        }
        return result;
    }
};

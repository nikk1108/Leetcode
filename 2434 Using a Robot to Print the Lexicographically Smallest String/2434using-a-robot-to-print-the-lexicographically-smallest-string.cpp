#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> mn(n);
        mn[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i)
            mn[i] = min(s[i], mn[i + 1]);

        stack<char> st;
        string res;
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            while (!st.empty() && (i == n - 1 || st.top() <= mn[i + 1])) {
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};

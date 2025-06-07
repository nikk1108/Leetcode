class Solution {
public:
    string smallestNumber(string p) {
        string res;
        stack<int> st;
        int cur = 1;
        for (int i = 0; i <= p.size(); ++i) {
            st.push(cur++);
            if (i == p.size() || p[i] == 'I') {
                while (!st.empty()) {
                    res += st.top() + '0';
                    st.pop();
                }
            }
        }
        return res;
    }
};

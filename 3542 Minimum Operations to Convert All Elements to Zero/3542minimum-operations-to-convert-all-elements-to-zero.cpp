class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        st.push(0);
        for (int num : nums) {
            while (!st.empty() && st.top() > num)
                st.pop();
            if (st.top() < num) {
                ans++;
                st.push(num);
            }
        }
        return ans;
    }
};

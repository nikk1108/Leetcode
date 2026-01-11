class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
                if (matrix.empty()) return 0;
                        int n = matrix[0].size();
                                vector<int> h(n, 0);
                                        int ans = 0;

                                                for (auto& row : matrix) {
                                                            for (int i = 0; i < n; i++) {
                                                                            h[i] = row[i] == '1' ? h[i] + 1 : 0;
                                                                                        }
                                                                                                    stack<int> st;
                                                                                                                for (int i = 0; i <= n; i++) {
                                                                                                                                int cur = (i == n ? 0 : h[i]);
                                                                                                                                                while (!st.empty() && cur < h[st.top()]) {
                                                                                                                                                                    int height = h[st.top()];
                                                                                                                                                                                        st.pop();
                                                                                                                                                                                                            int width = st.empty() ? i : i - st.top() - 1;
                                                                                                                                                                                                                                ans = max(ans, height * width);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                st.push(i);
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                };


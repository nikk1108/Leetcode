class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> st;
        vector<int> alive(n, 1);

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push_back(id);
            } else {
                while (!st.empty() && alive[id]) {
                    int j = st.back();

                    if (healths[j] < healths[id]) {
                        alive[j] = 0;
                        st.pop_back();
                        healths[id]--;
                    } else if (healths[j] > healths[id]) {
                        alive[id] = 0;
                        healths[j]--;
                    } else {
                        alive[id] = 0;
                        alive[j] = 0;
                        st.pop_back();
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (alive[i]) ans.push_back(healths[i]);
        }
        return ans;
    }
};
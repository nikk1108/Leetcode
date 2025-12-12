struct OfflineUser {
    int returnTimestamp;
    int userId;
    bool operator>(const OfflineUser& other) const {
        return returnTimestamp > other.returnTimestamp;
    }
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers);
        vector<int> online(numberOfUsers, true);
        priority_queue<OfflineUser, vector<OfflineUser>, greater<>> offlineQueue;

        int allMentions = 0;

        ranges::sort(events, ranges::less{}, [](const vector<string>& e) {
            return pair<int,char>{stoi(e[1]), -e[0][0]};
        });

        for (auto& e : events) {
            int time = stoi(e[1]);

            while (!offlineQueue.empty() && offlineQueue.top().returnTimestamp <= time) {
                online[offlineQueue.top().userId] = true;
                offlineQueue.pop();
            }

            if (e[0] == "MESSAGE") {
                string m = e[2];

                if (m == "ALL") {
                    allMentions++;
                } 
                else if (m == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++)
                        if (online[i]) ans[i]++;
                } 
                else {
                    for (int id : getUserIds(m))
                        ans[id]++;
                }
            } 
            else if (e[0] == "OFFLINE") {
                int u = stoi(e[2]);
                online[u] = false;
                offlineQueue.push({time + 60, u});
            }
        }

        for (int i = 0; i < numberOfUsers; i++)
            ans[i] += allMentions;

        return ans;
    }

private:
    vector<int> getUserIds(const string& s) {
        vector<int> v;
        istringstream iss(s);
        for (string x; iss >> x;)
            v.push_back(stoi(x.substr(2)));
        return v;
    }
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for (int x : arr) freq[x]++;

        set<int> seen;
        for (auto it : freq) {
            int count = it.second;
            if (seen.find(count) != seen.end()) return false;
            seen.insert(count);
        }
        return true;
    }
};

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for(const string& w : words )
            {
                int s=0;
                for (char x:w)
                    s+= weights[x-'a'];
                int r= s% 26;
                ans.push_back(char ('z'-r));
            }
        return ans;
    }
};
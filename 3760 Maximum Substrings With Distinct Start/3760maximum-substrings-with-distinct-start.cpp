class Solution {
public:
    int maxDistinct(string s) {
        string v=s;
        vector<int> seen(26,0);
        for(char c:v)
            seen[c-'a']=1;
        return accumulate(seen.begin(),seen.end(),0);
    }
};
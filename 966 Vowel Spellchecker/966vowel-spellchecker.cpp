class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        auto toLower = [](string s) {
            for (auto& c : s) c = tolower(c);
            return s;
        };
        
        auto devowel = [&](string s) {
            for (auto& c : s) {
                char low = tolower(c);
                if (low=='a' || low=='e' || low=='i' || low=='o' || low=='u')
                    c = '*';
                else
                    c = low;
            }
            return s;
        };
        
        for (string& w : wordlist) {
            string lower = toLower(w);
            if (!caseMap.count(lower)) caseMap[lower] = w;
            
            string vow = devowel(lower);
            if (!vowelMap.count(vow)) vowelMap[vow] = w;
        }
        
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            
            string lower = toLower(q);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            
            string vow = devowel(lower);
            if (vowelMap.count(vow)) {
                ans.push_back(vowelMap[vow]);
                continue;
            }
            
            ans.push_back("");
        }
        
        return ans;
    }
};

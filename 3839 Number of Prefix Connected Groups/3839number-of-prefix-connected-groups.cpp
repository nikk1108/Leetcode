class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        vector<string> vr= words;
        unordered_map<string, vector <int>> b;
        int n = vr.size();
        for (int i=0;i<n;i++)
            {
                if((int ) vr[i].size()<k) continue;
                string key = "";
                for (int j=0;j<k;++j)
                    key +=vr[i][j];
                b[key].push_back(i);
            }
        int ansr=0;
        for (auto &itt:b)
            if ((int)itt.second.size()>=2)
                ansr++;
        return ansr;
    }
};
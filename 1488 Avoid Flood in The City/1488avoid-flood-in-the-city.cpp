#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        set<int> s;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                s.insert(i);
                res[i]=1;
            } else {
                if(m.count(arr[i])){
                    auto it=s.lower_bound(m[arr[i]]);
                    if(it==s.end()) return {};
                    res[*it]=arr[i];
                    s.erase(it);
                }
                m[arr[i]]=i;
            }
        }
        return res;
    }
};

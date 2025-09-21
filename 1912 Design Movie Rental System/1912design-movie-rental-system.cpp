#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int s = e[0], m = e[1], p = e[2];
            available[m].insert({p, s});
            cost[{s, m}] = p;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        int k = 0;
        for (auto& [p, s] : available[movie]) {
            res.push_back(s);
            if (++k == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int p = cost[{shop, movie}];
        available[movie].erase({p, shop});
        inUse.insert({p, {shop, movie}});
    }

    void drop(int shop, int movie) {
        int p = cost[{shop, movie}];
        available[movie].insert({p, shop});
        inUse.erase({p, {shop, movie}});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int k = 0;
        for (auto& [p, sm] : inUse) {
            res.push_back({sm.first, sm.second});
            if (++k == 5) break;
        }
        return res;
    }

private:
    struct PairHash {
        size_t operator()(const pair<int,int>& pr) const {
            return pr.first * 1315423911u ^ pr.second;
        }
    };

    unordered_map<int, set<pair<int,int>>> available;
    unordered_map<pair<int,int>, int, PairHash> cost;
    set<pair<int, pair<int,int>>> inUse;
};

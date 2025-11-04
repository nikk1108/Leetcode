class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        long windowSum = 0;
        unordered_map<int,int> cnt;
        multiset<pair<int,int>> top, bot;
        auto update = [&](int num, int freq) {
            if (cnt[num] > 0) {
                auto itb = bot.find({cnt[num], num});
                if (itb != bot.end()) {
                    bot.erase(itb);
                } else {
                    auto itt = top.find({cnt[num], num});
                    top.erase(itt);
                    windowSum -= (long)num * cnt[num];
                }
            }
            cnt[num] += freq;
            if (cnt[num] > 0) bot.insert({cnt[num], num});
        };
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            update(nums[i], 1);
            if (i >= k) update(nums[i - k], -1);
            while (!bot.empty() && (int)top.size() < x) {
                auto it = prev(bot.end());
                auto [c, v] = *it;
                bot.erase(it);
                top.insert({c, v});
                windowSum += (long)v * c;
            }
            while (!bot.empty() && !top.empty() && *prev(bot.end()) > *top.begin()) {
                auto itb = prev(bot.end());
                auto [cb, vb] = *itb;
                bot.erase(itb);
                auto itt = top.begin();
                auto [ct, vt] = *itt;
                top.erase(itt);
                bot.insert({ct, vt});
                top.insert({cb, vb});
                windowSum += (long)vb * cb;
                windowSum -= (long)vt * ct;
            }
            if (i >= k - 1) ans.push_back((int)windowSum);
        }
        return ans;
    }
};

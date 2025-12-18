#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& actions, int k) {
        ll result = 0;
        int n = prices.size();
        vector<pair<ll,ll>> prefix(n);
        vector<pair<ll,ll>> suffix(n);

        suffix[n-1].first = prices[n-1] * actions[n-1];
        suffix[n-1].second = prices[n-1];
        result += prices[0] * actions[0];
        prefix[0].first = result;
        prefix[0].second = prices[0];

        for(int i = 1; i < n; i++){
            result += prices[i] * actions[i];
            prefix[i].first = result;
            prefix[i].second = prices[i] + prefix[i-1].second;
        }

        for(int i = n-2; i >= 0; i--){
            suffix[i].first = prices[i] * actions[i] + suffix[i+1].first;
            suffix[i].second = prices[i] + suffix[i+1].second;
        }

        for(int i = 0; i <= n - k; i++){
            ll leftProfit = (i-1 >= 0) ? prefix[i-1].first : 0;
            ll rightProfit = (i + k < n) ? suffix[i+k].first : 0;
            ll windowProfit = prefix[i+k-1].second - prefix[i+k/2-1].second;
            result = max(result, leftProfit + rightProfit + windowProfit);
        }

        return result;
    }
};

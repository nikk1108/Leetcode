class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        long long d[26][26];

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                d[i][j] = (i == j ? 0 : INF);

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            d[u][v] = min(d[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            long long v = d[source[i] - 'a'][target[i] - 'a'];
            if (v >= INF) return -1;
            ans += v;
        }

        return ans;
    }
};

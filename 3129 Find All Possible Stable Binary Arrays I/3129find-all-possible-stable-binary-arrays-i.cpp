class Solution {
public:
    int numberOfStableArrays(int z, int o, int lim) {
        const int MOD = 1000000007;

        vector<vector<long long>> end0(z+1, vector<long long>(o+1,0));
        vector<vector<long long>> end1(z+1, vector<long long>(o+1,0));

        for(int i=0;i<=z && i<=lim;i++) end0[i][0]=1;
        for(int j=0;j<=o && j<=lim;j++) end1[0][j]=1;

        for(int i=1;i<=z;i++){
            for(int j=1;j<=o;j++){

                long long ways0 = (end0[i-1][j] + end1[i-1][j]) % MOD;

                if(i-lim-1 >= 0)
                    ways0 = (ways0 - end1[i-lim-1][j] + MOD) % MOD;

                end0[i][j] = ways0;

                long long ways1 = (end0[i][j-1] + end1[i][j-1]) % MOD;

                if(j-lim-1 >= 0)
                    ways1 = (ways1 - end0[i][j-lim-1] + MOD) % MOD;

                end1[i][j] = ways1;
            }
        }

        return (end0[z][o] + end1[z][o]) % MOD;
    }
};
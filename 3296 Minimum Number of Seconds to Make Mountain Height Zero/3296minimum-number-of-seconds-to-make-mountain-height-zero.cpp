class Solution {
public:
    bool ok(long long T, int h, vector<int>& wt){
        long long done = 0;

        for(int t: wt){
            long long l = 0, r = 1e6;

            while(l <= r){
                long long m = (l + r) / 2;
                long long need = 1LL * t * m * (m + 1) / 2;

                if(need <= T) l = m + 1;
                else r = m - 1;
            }

            done += r;
            if(done >= h) return true;
        }

        return done >= h;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18, ans = r;

        while(l <= r){
            long long mid = (l + r) / 2;

            if(ok(mid, mountainHeight, workerTimes)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
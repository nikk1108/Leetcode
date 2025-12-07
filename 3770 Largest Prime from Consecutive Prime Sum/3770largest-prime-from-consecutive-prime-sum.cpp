class Solution {
public:
    
    int largestPrime(int n) {
  int lv=n;
        if (lv<2) return 0;
        vector <bool> isPrime(lv+1,true);
        isPrime[0]=isPrime[1]=false;
        for (int i=2;i*i<=lv;i++)
            if (isPrime[i])
                for (int j = i * i; j <= lv; j += i) 
                    isPrime[j] = false;
         vector<int> p;
        for (int i = 2; i <= lv; i++)
            if (isPrime[i]) p.push_back(i);

        long long sum =0;
        int ans =0;
        for (int x:p){
            sum +=x;
            if(sum>lv) break;
              if (isPrime[sum]) ans = sum;
        }
    
    
    return ans; }
};
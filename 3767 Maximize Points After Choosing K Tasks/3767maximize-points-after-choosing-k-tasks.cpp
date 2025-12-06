class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        vector <long long>d(n);
        int cd;
        long long sum =0;
        for (int i=0;i<n;i++)
            {  cd=i;
             sum = sum + t2[i];
             d[i]=(long long)t1[i]-t2[i];
                  }
        sort (d.rbegin(),d.rend());
        for (int i=0;i<k;i++) sum = sum +d[i];
        for (int i=k;i<n;i++) {
            if (d[i]>0) sum = sum + d[i];
            else break; } return sum;
    }
};
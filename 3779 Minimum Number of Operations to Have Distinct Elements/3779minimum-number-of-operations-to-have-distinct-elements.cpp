class Solution {
public:
    int minOperations(vector<int>& nums) {
 int n=nums.size();
        vector<int> f(100001, 0);
         int hd = 0;
        for (int i=0;i<n;i++)
            {  f[nums[i]]++;
       if(f[nums[i]] == 2) hd++; }
        int ps=0,os=0;
        while(ps<n && hd>0){ 
     os++;
            int r=0;
                     while(r<3 && ps<n) {
                      int v=nums[ps];
                    if(f[v]==2) hd--;
                      f[v]--;
                         ps++; 
                         r++;
                     }  
       
    } return os;
    }
};
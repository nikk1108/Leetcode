class Solution {
public:
    int reflect(int x)
    {
        int r=0;
        while(x>0)
            {
                r=(r<<1)|(x&1);
              x=  x>>1;
            } return r;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int ra=reflect(a);
            int rb= reflect(b);
            if (ra == rb) return a < b;
            return ra < rb;
    });
        return nums; }
};
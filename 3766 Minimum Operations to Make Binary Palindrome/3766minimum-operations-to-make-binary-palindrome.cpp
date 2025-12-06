class Solution {
public:
    bool p (int x)
    {
        string s;
        while(x>0)
            {
                s= s+ char((x%2)+'0');
                x=x/2;
            }
        string r=s;
        reverse (r.begin(),r.end());
        return s==r;

    }
    int cp(int num)
    {  int os=0;
     while(true)
         {    if (num-os>0 && p(num-os)) return os;
    if (os>0&& p(num+os)) return os;
     os ++;
    }   
    }
    vector<int> minOperations(vector<int>& nums) {
      vector<int> ans;
     int rv;
        for (int i=0;i<nums.size();i++)
            {    rv=nums[i];
        ans.push_back(cp(rv)); } return ans;
    }
};
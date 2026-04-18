class Solution {
public:
    int mirrorDistance (int n) 
{   int r=0;
   int b= n;
    while (n>0)
    { int d= n%10;
      r = r*10+d;
      n= n/10;
    }
    return abs(r-b);
}

       
};
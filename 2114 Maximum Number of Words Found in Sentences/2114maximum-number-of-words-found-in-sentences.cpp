class Solution {
public:
    int mostWordsFound(vector<string>& s) {
   int maxi=0;
  for (string x : s)
 { int c=1;
   for(char a : x)
   if(a == ' ') c++; 
            
            if(c > maxi)
                maxi = c;      
        }

        return maxi;
    }
};
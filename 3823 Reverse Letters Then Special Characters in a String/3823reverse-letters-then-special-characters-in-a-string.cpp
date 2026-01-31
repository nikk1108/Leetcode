class Solution {
public:
    string reverseByType(string s) {
       string a,b;
        for (char c:s)
            {
                (c >= 'a' && c <= 'z' ? a : b).push_back(c);
            }
        reverse(a.begin(),a.end());
         reverse(b.begin(),b.end());
        int i=0,j=0;
        for(char &c:s)
             c = (c >= 'a' && c <= 'z') ? a[i++] : b[j++];
        return s;
    }
};
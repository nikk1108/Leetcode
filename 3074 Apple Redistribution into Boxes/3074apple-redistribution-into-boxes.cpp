class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
      
         int t=0;
         for (int x: apple)
         t += x;
  sort (capacity.begin(),capacity.end(),greater <int>());
int sum=0, cnt =0;
for (int x:capacity){
    sum += x;
cnt ++;
if (sum>=t)
 return cnt; }
    return cnt; }
};
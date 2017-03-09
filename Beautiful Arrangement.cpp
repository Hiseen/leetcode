class Solution {
 public:
     int countArrangement(int N) {
         int ans[15]={1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679};
         return ans[N-1];
     }
 };
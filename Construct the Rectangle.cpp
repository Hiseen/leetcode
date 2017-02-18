class Solution {
 public:
     vector<int> constructRectangle(int area) {
         int s=sqrt(area);
         while(area%s)s--;
         return {area/s,s};
     }
 };
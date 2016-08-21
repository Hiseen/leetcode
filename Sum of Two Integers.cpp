class Solution {
 public:
     int getSum(int a, int b) {
         if(a==b)return a<<1;
         int rb=(a&b)<<1,ra=a^b;
         while(rb!=0)
         {
             int newa=ra^rb;
             int newb=(ra&rb)<<1;
             ra=newa;
             rb=newb;
         }
         return ra;
     }
 };
class Solution {
 public:
     int arrangeCoins(int n) {
         int i=1;
         int res=0;
         while(n>0)
         {
             n-=i++;
             res+=1;
         }
         return n<0?res-1:res;
     }
 };
class Solution {
 public:
     int integerBreak(int n) {
         if(n==2)
             return 1;
         if(n==3)
             return 2;
         int dp[10]{1,1,2,3,4,6,9,12,18,27};
         if(n>3 &&n<10)
             return dp[n];
         else
         {
             int res=1;
             while(n>=10)
             {
                 n-=3;
                 res*=3;
             }
             return dp[n]*res;
         }
     }
 };
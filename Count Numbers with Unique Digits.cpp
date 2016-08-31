class Solution {
 public:
     int countNumbersWithUniqueDigits(int n) {
         if(n>=10)
             return 8877691;
         else if(n==0)
             return 1;
         else
         {
            int dp[10];
            dp[1]=10;
            for(int i=2;i<=n;++i)
            {
                int p=9;
                for(int j=1;j<i;j++)p*=10-j;
                dp[i]=p+dp[i-1];
            }
            return dp[n];
         }
     }
 };
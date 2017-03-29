class Solution {
 public:
     int uniquePaths(int m, int n) {
         int dp[120][120];
         for(int i=0;i<m;++i)
         for(int j=0;j<n;++j)
             dp[i][j]=0;
         int i=0;
         int j=0;
         dp[0][0]=1;
         while(i!=m-1 || j!=n-1)
         {
             int nexti,nextj;
             if(j!=n-1)
             {
                 nextj=j+1;
                 nexti=0;
             }
             else
             {
                 nextj=j;
                 nexti=i+1;
             }
             while(i>=0 && j>=0 && i<m && j<n)
             {
                 if(j+1<n)
                     dp[i][j+1]+=dp[i][j];
                 if(i+1<m)
                     dp[i+1][j]+=dp[i][j];
                 ++i;
                 --j;
             }
             i=nexti;
             j=nextj;
         }
         return dp[m-1][n-1];
     }
 };
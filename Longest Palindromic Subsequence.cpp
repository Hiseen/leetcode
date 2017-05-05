class Solution {
 public:
     int longestPalindromeSubseq(string s) {
         if(s.size()==0)return 0;
         if(s.size()==1)return 1;
         int dp[1000];
         int pre_dp[1000];
         int post_dp[1000];
         int size=s.size();
         int cpsize=sizeof(int)*size;
         for(int i=0;i<1000;++i)
             pre_dp[i]=1;
         for(int i=0;i<size-1;++i)
             if(s[i]==s[i+1])
                 dp[i]=2;
             else
                 dp[i]=1;
         for(int i=2;i<size;++i)
         {
             for(int j=0;j+i<size;++j)
             {
                 if(s[j]==s[j+i])
                     post_dp[j]=2+pre_dp[j+1];
                 else
                     post_dp[j]=max(dp[j],dp[j+1]);
             }
             memcpy(pre_dp,dp,cpsize);
             memcpy(dp,post_dp,cpsize);
         }
         return dp[0];
     }
 };
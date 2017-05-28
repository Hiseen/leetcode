class Solution {
 public:
     int minDistance(string word1, string word2) {
         int dp[501][501]={0};
         int len1=word1.size();
         int len2=word2.size();
         for(int i=0;i<len1;++i)
         for(int j=0;j<len2;++j)
         {
             if(word1[i]==word2[j])
                 dp[i+1][j+1]=dp[i][j]+1;
             else
             {
                 dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
             }
         }
         return len1-dp[len1][len2]*2+len2;
     }
 };
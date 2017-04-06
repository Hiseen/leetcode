class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         int size=triangle.size();
         if(size==1)return triangle[0][0];
         int dp[1000];
         int res=INT_MAX;
         dp[0]=triangle[0][0];
         int last=dp[0];
         for(int i=1;i<size;++i)
         {
             for(int j=i-1;j>=0;--j)
             {
                 dp[j]=(j-1>=0?min(dp[j],dp[j-1]):dp[j])+triangle[i][j];
                 if(i==size-1 && res>dp[j])res=dp[j];
             }
             last+=triangle[i][i];
             dp[i]=last;
         }
         return res<last?res:last;
     }
 };
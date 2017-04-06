class Solution {
 public:
     bool canPartition(vector<int>& nums) {
         int sum=0;
         for(auto i:nums)
             sum+=i;
         if(sum%2)return false;
         int target=sum>>1;
         int dp[10000]={0};
         for(auto i:nums)
         {
            for(int j=target;j>=i;--j)
               dp[j]=max(dp[j],dp[j-i]+i);
            if(dp[target]==target)return true;
         }
         return false;
         
     }
 };
class Solution {
 public:
     int findTargetSumWays(vector<int>& nums, int S) {
         unordered_map<int,int> dp[20];
         int size=nums.size();
         ++dp[0][nums[0]];
         ++dp[0][-nums[0]];
         for(int i=1;i<size;++i)
         {
             for(auto j:dp[i-1])
             {
                 dp[i][j.first+nums[i]]+=j.second;
                 dp[i][j.first-nums[i]]+=j.second;
             }
         }
         return dp[size-1][S];
     }
 };
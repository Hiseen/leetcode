class Solution {
 public:
     vector<int> largestDivisibleSubset(vector<int>& nums) {
         if(nums.empty())return vector<int>();
         if(nums.size()==1)return nums;
         vector<vector<int>> dp;
         sort(nums.begin(),nums.end());
         for(auto i:nums)
         {
             bool f=false;
             int sz=dp.size();
             int target=0;
             int tarlen=0;
             for(int j=0;j<sz;++j)
             {
                 if(i%dp[j][dp[j].size()-1]==0)
                 {
                     if(dp[j].size()>tarlen)
                     {
                         target=j;
                         tarlen=dp[j].size();
                     }
                     f=true;
                     
                 }
             }
             if(!f)
                 dp.push_back(vector<int>{i});
             else
             {
                 dp.push_back(dp[target]);
                 dp[dp.size()-1].push_back(i);
             }
         }
         int maxsize=0;
         int index=0;
         for(int i=0;i<dp.size();++i)
             if(dp[i].size()>maxsize){maxsize=dp[i].size();index=i;}
         return dp[index];
     }
 };
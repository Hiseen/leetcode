class Solution {
 public:
 
     int robhelper(vector<int> &nums, int start,int end)
     {
             int dp[100000];
             dp[0]=nums[start];
             dp[1]=nums[start]>nums[start+1]?nums[start]:nums[start+1];
             for(int i=2;i<=end-start;i++)
             {
                 int temp1=dp[i-1];
                 int temp2=dp[i-2]+nums[start+i];
                 dp[i]=temp1>temp2?temp1:temp2;
             }
             return dp[end-start];
     }
 
     int rob(vector<int>& nums) {
         if(nums.size()==0)
             return 0;
         else if(nums.size()==1)
             return nums[0];
         else if(nums.size()==2)
             return nums[0]>nums[1]?nums[0]:nums[1];
         int res1=robhelper(nums,0,nums.size()-2),res2=robhelper(nums,1,nums.size()-1);
         return res1>res2?res1:res2;
     }
 };
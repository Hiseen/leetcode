class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int dp[100000];
        dp[0]=nums[0];
        dp[1]=nums[0]>nums[1]?nums[0]:nums[1];
        for(int i=2;i<nums.size();i++)
        {
            int temp1=dp[i-1];
            int temp2=dp[i-2]+nums[i];
            dp[i]=temp1>temp2?temp1:temp2;
        }
        return dp[nums.size()-1];
    }
};
class Solution {
 public:
     int wiggleMaxLength(vector<int>& nums) {
         if(nums.empty())return 0;
         int dp;
         int size=nums.size();
         int start=0;
        	bool flag = nums[0]==nums[1];
        	if(flag)
     	for (int i = 0; i<size - 1; ++i)
     	{
         	 if(nums[i]!=nums[i+1])
         	    break;
         	 else
         	    start++;
     	}
     	if (start == size - 1)return 1;
     	flag=nums[start]<nums[start+1];
     	dp = 2;
     	for (int i = start+1; i<size-1; ++i)
     	{
     		if (flag)
     		{
     			if (nums[i+1]<nums[i])
     			{
     				dp++;
     				flag = !flag;
     			}
     		}
     		else
     		{
     			if (nums[i+1]>nums[i])
     			{
     				dp++;
     				flag = !flag;
     			}
     		}
     	}
     	return dp;
     }
 };
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
           return 1;
           for(int i=0;i<nums.size();)
           {
               if(nums[i]>0)
               {
                   for(int j=i;j<nums.size();)
                      if(i!=j && nums[i]==nums[j])
                        nums.erase(nums.begin()+j);
                      else
                       j++;
                       i++;
               }
               else
                  nums.erase(nums.begin()+i);
           }
           
           
        sort(nums.begin(),nums.end());
        if(nums[0]>1)
        return 1;
        int start=0;
        for(int i=0;i<nums.size();i++)
            {
                start++;
                if(nums[i]!=start)
                   return start>1?start:1;
            }
        return nums[0]<=1?nums[nums.size()-1]+1:nums[0]-1;
    }
};
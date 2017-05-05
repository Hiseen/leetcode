class Solution {
 public:
     bool checkSubarraySum(vector<int>& nums, int k) {
         int size=nums.size();
         for(int i=1;i<size;++i)
             nums[i]+=nums[i-1];
         for(int i=1;i<size;++i)
         {
             for(int j=-1;j<i-1;++j)
             {
                 if(k==0)
                 {
                     if(j==-1 && nums[i]==0)
                         return true;
                     else if((nums[i]-nums[j])==0)
                         return true;
                 }
                 else
                 {
                     if(j==-1 && nums[i]%k==0)
                         return true;
                     else if((nums[i]-nums[j])%k==0)
                         return true;
                 }
             }
         }
         return false;
     }
 };
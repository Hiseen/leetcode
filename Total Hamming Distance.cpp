class Solution {
 public:
     int totalHammingDistance(vector<int>& nums) {
         int result=0;
         int size=nums.size();
         for(;;)
         {
             bool all0=true;
             int count0=0;
             int count1=0;
             for(int i=0;i<size;++i)
             {
                 if(all0 && nums[i]!=0)all0=false;
                 if(nums[i]%2)
                     ++count1;
                 else
                     ++count0;
                 nums[i]>>=1;
             }
             if(all0)break;
             result+=count0*count1;
         }
         return result;
     }
 };
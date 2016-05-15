class Solution {
 public:
     vector<int> singleNumber(vector<int>& nums) {
         int result=0,size=nums.size();
         for(int i=0;i<size;++i)
             result^=nums[i];
         int slice=result&(~(result-1));
         int num1=0,num2=0;
         for(int i=0;i<size;++i)
             if((nums[i]&slice)!=0)
                 num1^=nums[i];
             else
                 num2^=nums[i];
         return {num1,num2};
     }
 };
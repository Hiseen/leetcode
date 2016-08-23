class Solution {
 public:
     int jump(vector<int>& nums) {
         if(nums.size()<=1)return 0;
         int result=1;
         int jumpindex=nums[0];
         int nowindex=0;
         int size=nums.size();
         while(nowindex+jumpindex<size-1)
         {
             result++;
             int max=0,tempindex=nowindex;
             for(int i=1;i<=jumpindex;++i)
             {
                 if(max<nowindex+i+nums[nowindex+i])
                 {
                     max=nowindex+i+nums[nowindex+i];
                     tempindex=nowindex+i;
                 }
             }
             nowindex=tempindex;
             jumpindex=nums[nowindex];
         }
         return result;
     }
 };
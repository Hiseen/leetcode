class Solution {
 public:
     vector<int> nextGreaterElements(vector<int>& nums) {
         vector<int> res;
         int size=nums.size();
         if(size==0)return res;
         for(int i=0;i<size;++i)
         {
             int temp=nums[i];
             int k=0;
             bool flag=false;
             for(int j=i;j<size;++j)
             {
                 if(nums[j]>temp)
                 {
                     flag=true;
                     temp=nums[j];
                     break;
                 }
             }
             if(!flag)
             {
                 for(int j=0;j<i;++j)
                 {
                     if(nums[j]>temp)
                     {
                         flag=true;
                         temp=nums[j];
                         break;
                     }
                 }
             }
             if(!flag)
                 res.push_back(-1);
             else
                 res.push_back(temp);
         }
         return res;
     }
 };
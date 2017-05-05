class Solution {
 public:
     int lengthOfLIS(vector<int>& nums) {
         if(nums.empty())return 0;
         vector<int> v;
         v.push_back(0);
         for(int i=1;i<nums.size();++i)
         {
             if(nums[i]>nums[v.back()])
                 v.push_back(i);
             else
             {
                 for(int j=0;j<v.size();++j)
                 {
                     if(nums[i]<nums[v[j]] && (j==0 ||nums[i]>nums[v[j-1]]))
                     {
                         v[j]=i;
                         break;
                     }
                 }
             }
         }
         return v.size();
         
     }
 };
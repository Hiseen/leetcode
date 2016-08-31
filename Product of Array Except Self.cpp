class Solution {
 public:
     vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> res;
         int size=nums.size();
         int p=nums[0];
         for(int i=0;i<size-1;++i)
         {
             res.push_back(p);
             p*=nums[i+1];
         }
         p=nums[size-1];
         for(int i=size-2;i>0;--i)
         {
             res[i-1]*=p;
             p*=nums[i];
         }
         res.insert(res.begin(),p);
         return res;
     }
 };
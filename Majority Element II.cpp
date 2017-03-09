class Solution {
 public:
     vector<int> majorityElement(vector<int>& nums) {
         if(nums.size()==0)return vector<int>();
         sort(nums.begin(),nums.end());
         unordered_set<int> s;
         int size=nums.size();
         int step=size/3;
         for(int i=0;i<size-step;)
         {
             if(nums[i]==nums[i+step])
             {
                 s.insert(nums[i]);
                 i+=step+1;
             }
             else
                 ++i;
         }
         vector<int> res;
         for(auto i:s)
         {
             res.push_back(i);
         }
         return res;
     }
 };
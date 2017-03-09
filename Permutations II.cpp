class Solution {
 public:
 
 
     void recur(vector<vector<int>>& res,vector<int>& nums,int now,int max)
     {
         unordered_set<int> s;
         if(now<max)recur(res,nums,now+1,max);
         for(int i=now+1;i<max;++i)
         {
             if(nums[i]!=nums[now])
             {
                 if(s.find(nums[i])==s.end())
                 {
                     s.insert(nums[i]);
                     swap(nums[i],nums[now]);
                     res.push_back(nums);
                     recur(res,nums,now+1,max);
                     swap(nums[i],nums[now]);
                 }
             }
         }
     }
 
 
 
     vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> res;  
         res.push_back(nums);
         recur(res,nums,0,nums.size());
         return res;
         
     }
 };
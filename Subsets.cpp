class Solution {
 public:
     vector<vector<int>> subsets(vector<int>& nums) {
         int size=nums.size();
         vector<vector<int>> result;
         result.push_back(vector<int>());
         if(size==0)return result;
         long long count=1<<size;
         for(int i=1;i<count;++i)
         {
             vector<int> temp;
             for(int j=0;j<size;j++)
                 if((i>>j)&1)temp.push_back(nums[j]);
             result.push_back(temp);
         }
         return result;
     }
 };
class Solution {
 public:
     int longestConsecutive(vector<int>& nums) {
         if(nums.size()<=1)
             return nums.size();
         unordered_set<int> hash,trans(nums.begin(),nums.end());
         int max=0,size=nums.size();
         for(int k=0;k<size;++k)
         {
             int i=nums[k];
             if(!(hash.find(i)!=hash.end()))
             {
                 hash.insert(i);
                 int low=i-1,high=i+1;
                 while(trans.find(low)!=trans.end())
                     hash.insert(low--);
                 while(trans.find(high)!=trans.end())
                     hash.insert(high++);
                 if(max<high-low-1)
                     max=high-low-1;
             }
                 
         }
         return max;
         
     }
 };
class Solution {
 public:
     int minMoves2(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int size=nums.size();
         if(size==0)return 0;
         int mid=size/2;
         int res=0;
         for(int i=0;i<size;++i)
             res+=abs(nums[mid]-nums[i]);
         return res;
     }
 };
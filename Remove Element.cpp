class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int size=nums.size(),count=0;
         vector<int>::iterator iter;
         for(iter=nums.begin();iter!=nums.end();)
             if(val!=*iter)
             {
                 count++;
                 ++iter;
             }
             else
                 iter=nums.erase(iter);
         return count;
     }
 };
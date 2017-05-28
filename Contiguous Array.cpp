class Solution {
 public:
     int findMaxLength(vector<int>& nums) {
         if(nums.empty()||nums.size()<2)return 0;
         if(nums.size()==2)
             return nums[0]!=nums[1]?2:0;
         int size=nums.size();
         unordered_map<int,int> h;
         int now=0;
         h[0]=-1;
         int res=0;
         for(int i=0;i<size;++i)
         {
             if(nums[i])
                 now++;
             else
                 now--;
             if(h.find(now)==h.end())
                 h[now]=i;
             else
                 if(res<i-h[now])res=i-h[now];
         }
         return res;
     }
 };
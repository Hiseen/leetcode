class Solution {
 public:
     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
         int size=timeSeries.size();
         if(!size)return 0;
         int now=0;
         int res=0;
         for(auto i:timeSeries)
         {
             if(now>i)
                 res+=duration-(now-i);
             else
                 res+=duration;
             now=i+duration;
         }
         return res;
     }
 };
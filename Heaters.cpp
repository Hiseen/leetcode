class Solution {
 public:
     int findRadius(vector<int>& houses, vector<int>& heaters) {
         int size=heaters.size();
         int size2=houses.size();
         if (size==0)
             return 0;
         int lh=INT_MAX;
         int rh=INT_MIN;
         for(auto i:houses)
         {
             if(lh>i)lh=i;
             if(rh<i)rh=i;
         }
         if(size==1)
             return max(abs(heaters[0]-lh),abs(heaters[0]-rh));
         sort(heaters.begin(),heaters.end());
         sort(houses.begin(),houses.end());
         int index=0;
         int max=0;
         for(int i=0;i<size2;)
         {
             if(index+1<size && abs(houses[i]-heaters[index])>=abs(houses[i]-heaters[index+1]))
                 ++index;
             else
             {
                 if(abs(houses[i]-heaters[index])>max)
                     max=abs(houses[i]-heaters[index]);
                 ++i;
             }
         }
         return max;
     }
 };
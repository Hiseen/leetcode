class Solution {
 public:
     int numberOfBoomerangs(vector<pair<int, int>>& points) {
         int res=0;
         for(auto i:points)
         {
             unordered_map<int,int> um;
             for(auto j:points)
             {
                 int dx=i.first-j.first;
                 int dy=i.second-j.second;
                 um[dx*dx+dy*dy]+=1;
             }
             for(auto k:um)
             {
                 int t=k.second;
                 if(t>=2)
                     res+=t*(t-1);
             }
         }
         return res;
     }
 };
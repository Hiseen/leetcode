class Solution {
 public:
     bool isSelfCrossing(vector<int>& x) {
         int size=x.size();
         for(int i=3;i<size;++i)
         {
             if(x[i]>=x[i-2] && x[i-1]<=x[i-3])
                 return true;
             if(i>3 && x[i]+x[i-4]>=x[i-2] && x[i-1]==x[i-3])
                 return true;
             if(i>4 && x[i]+x[i-4]>=x[i-2] && x[i-1]+x[i-5]>=x[i-3] && x[i-1]<=x[i-3] && x[i-3]>x[i-5] && x[i-2]>=x[i-4])
                 return true;
         }
         return false;
     }
 };
class Solution {
 public:
     int findContentChildren(vector<int>& g, vector<int>& s) {
         if(s.size()==0)return 0;
         int result=0;
         sort(s.begin(),s.end());
         for(auto i:g)
         {
            int lo=0;
            int hi=s.size()-1;
            if(s[hi]>=i)
             {
                 while(lo<hi)
                 {
                     int mid=(lo+hi)>>1;
                     if(s[mid]>i)
                         hi=mid;
                     else
                     lo=mid+1;
                 }
                 ++result;
                 s.erase(s.begin()+lo);
            }
         }
         return result;
     }
 };
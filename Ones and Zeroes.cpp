class Solution {
 public:
     int findMaxForm(vector<string>& strs, int m, int n) {
         unordered_set<int> set;
         set.insert((m<<7)+n);
         int res=0;
         int left=strs.size();
         for(auto i:strs)
         {
             int count0=0;
             int count1=0;
             for(auto k:i)
             {
                 if(k=='0')++count0;
                 else ++count1;
             }
             unordered_set<int> tempset;
             for(auto j:set)
             {
                 int j0=(j&16760832)>>14,j1=(j&16256)>>7,j2=j&127;
                 if(j0+left>=res && j1>=count0 && j2>=count1)
                 {
                     if(res<j0+1)res=j0+1;
                     tempset.insert(((j0+1)<<14)+((j1-count0)<<7)+j2-count1);
                 }
             }
             for(auto j:tempset)
                 set.insert(j);
             --left;
         }
         return res;
     }
 };
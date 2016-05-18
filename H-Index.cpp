class Solution {
 public:
     int hIndex(vector<int>& citations) {
         sort(citations.begin(),citations.end());
         int size=citations.size();
         for(int i=1;i<=size;++i)
         {
             if(i>citations[size-i])
                 return i-1;
         }
         return size;
     }
 };
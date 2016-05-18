class Solution {
 public:
     int hIndex(vector<int>& citations) {
         if(citations.size()==0)return 0;
         int start=1,mid,end=citations.size(),size=end;
         if(citations.size()==1)
             return citations[0]?1:0;
         if(1>citations[size-1])return 0;
         if(size<=citations[0])return size;
         while(start<end)
         {
             mid=start/2+end/2;
             if(mid>citations[size-mid])
                 end=mid;
             else
                 start=mid+1;
         }
         return start-1;
     }
 };
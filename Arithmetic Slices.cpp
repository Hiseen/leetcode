class Solution {
 public:
     int numberOfArithmeticSlices(vector<int>& A) {
         if(A.size()<3)return 0;
         int result=0;
         int diff=A[0]-A[1];
         int last=A[1];
         int count=2;
         int size=A.size();
         for(int i=2;i<size;++i)
         {
             int temp=A[i];
             if(last-temp==diff)
                 ++count;
             else
             {
                 count=2;
                 diff=last-temp;
             }
             if(count>=3)
                 result+=count-2;
             last=temp;
         }
         return result;
     }
 };
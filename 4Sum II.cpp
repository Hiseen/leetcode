class Solution {
 public:
     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
         unordered_map<int,int> AandB;
         int size=A.size();
         int result=0;
         if(size==0)return 0;
         for(int i=0;i<size;++i)
         for(int j=0;j<size;++j)
             ++AandB[A[i]+B[j]];
         for(int i=0;i<size;++i)
         for(int j=0;j<size;++j)
         {
             int t=-(C[i]+D[j]);
             if(AandB.find(t)!=AandB.end())
                 result+=AandB[t];
         }
         return result;
     }
 };
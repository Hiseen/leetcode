class Solution {
 public:
     vector<int> getRow(int rowIndex) {
         vector<int> result{1};
         for(int i=0;i<rowIndex;++i)
         {
             int size=result.size()-1;
             for(int j=0;j<size;++j)
                 result[j]+=result[j+1];
             result.insert(result.begin(),1);
         }
         return result;
     }
 };
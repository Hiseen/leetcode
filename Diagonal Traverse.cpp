class Solution {
 public:
     vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
         vector<int> res;
         int size1=matrix.size();
         if(size1==0)return res;
         int size2=matrix[0].size();
         if(size2==0)return res;
         res.push_back(matrix[0][0]);
         if(size1==1 && size2==1)return res;
         int i=0;
         int j=0;
         while(1)
         {
             if(j==size2-1)++i;
             else ++j;
             res.push_back(matrix[i][j]);
             if(j==size2-1 && i==size1-1)break;
             while(j!=0 && i!=size1-1){++i;--j;res.push_back(matrix[i][j]);}
             if(i==size1-1)++j;
             else ++i;
             res.push_back(matrix[i][j]);
             if(j==size2-1 && i==size1-1)break;
             while(i!=0 && j!=size2-1){++j;--i;res.push_back(matrix[i][j]);}
             
         }
         return res;
     }
 };
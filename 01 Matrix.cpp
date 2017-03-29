class Solution {
 public:
 
     bool helper1(const vector<vector<int>>& matrix,int i,int j,int size1,int size2)
     {
         if(i-1>=0 && matrix[i-1][j]==0)return true;
         else if(j-1>=0 && matrix[i][j-1]==0)return true;
         else if(j+1<size2 && matrix[i][j+1]==0)return true;
         else if(i+1<size1 && matrix[i+1][j]==0)return true;
         return false;
     }
     
     int helper2(vector<vector<int>>& res,int i,int j,int size1,int size2)
     {
         if(i<0 || j<0 || i>=size1 || j>=size2)return INT_MAX;
         if(res[i][j]==1000000)
         {
             res[i][j]--;
             int a1=helper2(res,i+1,j,size1,size2);
             int a2=helper2(res,i-1,j,size1,size2);
             int a3=helper2(res,i,j+1,size1,size2);
             int a4=helper2(res,i,j-1,size1,size2);
             res[i][j]=1+min(min(a1,a2),min(a3,a4));
         }
         else
         {
             if(i-1>=0 && res[i-1][j]+1<res[i][j])res[i][j]=res[i-1][j]+1;
             if(j-1>=0 && res[i][j-1]+1<res[i][j])res[i][j]=res[i][j-1]+1;
         }
         return res[i][j];
     }
 
     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
         if(matrix.size()==1 && matrix[0].size()==1)return matrix;
         vector<vector<int>> res;
         int size1=matrix.size();
         int size2=matrix[0].size();
         res.resize(size1,vector<int>(size2,1000000));
         for(int i=0;i<size1;++i)
         for(int j=0;j<size2;++j)
             if(matrix[i][j]==0)
                 res[i][j]=0;
             else if(helper1(matrix,i,j,size1,size2))
                 res[i][j]=1;
         for(int i=0;i<size1;++i)
         for(int j=0;j<size2;++j)
             helper2(res,i,j,size1,size2);
                 
         return res;
     }
 };
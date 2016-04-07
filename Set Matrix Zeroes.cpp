class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cleanfirst=false;
        for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[i].size();j++)
        {
            if(!matrix[i][j])
            {
                if(i==0)
                cleanfirst=true;
                else
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++)
            if(!matrix[i][0])
               for(int k=0;k<matrix[i].size();k++)
                   matrix[i][k]=0;
        for(int i=0;i<matrix[0].size();i++)
            if(!matrix[0][i])
               for(int k=0;k<matrix.size();k++)
                   matrix[k][i]=0;
                   if(cleanfirst)
                 for(int k=0;k<matrix[0].size();k++)
                 matrix[0][k]=0;
    }
};
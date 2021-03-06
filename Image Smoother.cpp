class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row_count=M.size();
        if(!row_count)return M;
        int col_count=M[0].size();
        if(!col_count)return M;
        vector<vector<int>> result(M);
        for(int i=0;i<row_count;++i)
        for(int j=0;j<col_count;++j)
        {
            int t=0;
            int c=0;
            for(int m=i-1;m<i+2;++m)
            for(int n=j-1;n<j+2;++n)
            {
                if(m>=0 && n>=0 && m<row_count && n<col_count)
                {
                    ++c;
                    t+=M[m][n];
                }
            }
            result[i][j]=t/c;
        }
        return result;
    }
};
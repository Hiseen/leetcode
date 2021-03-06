class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty())return;
        if(matrix[0].empty())return;
        dp.swap(matrix);
        i_sz=dp.size();
        j_sz=dp[0].size();
        for(int j=j_sz-1;j>=0;--j)
        for(int i=i_sz-1;i>=0;--i)
        {
            if(i+1<i_sz)
                dp[i][j]+=dp[i+1][j];
            if(j+1<j_sz)
                dp[i][j]+=dp[i][j+1];
            if(i+1<i_sz && j+1<j_sz)
                dp[i][j]-=dp[i+1][j+1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int p1=col2+1<j_sz?dp[row1][col2+1]:0;
        int p2=row2+1<i_sz?dp[row2+1][col1]:0;
        int p=row1<i_sz && col1<j_sz?dp[row1][col1]:0;
        if(col2+1<j_sz && row2+1<i_sz)
            p+=dp[row2+1][col2+1];
        return p-p1-p2;
    }
    
    
    
    
private:
    vector<vector<int>> dp;
    int i_sz;
    int j_sz;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
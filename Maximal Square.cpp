class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        bool dp[1000][1000];
        int len=0;
        int i_sz=matrix.size();
        int j_sz=matrix[0].size();
        for(int i=0;i<i_sz;++i)
        for(int j=0;j<j_sz;++j)
            dp[i][j]=true;  
        int maxlen=min(i_sz,j_sz);
        while(len<maxlen)
        {
            bool f=false;
            for(int i=0;i<i_sz;++i)
            for(int j=0;j<j_sz;++j)
            {
                if(dp[i][j])
                {
                    bool flag=true;
                    if(j+len<j_sz && i+len<i_sz)
                    {
                        for(int k=i;k<=i+len;++k)
                        if(matrix[k][j+len]=='0')flag=false;
                    }
                    else flag=false;
                    if(i+len<i_sz && j+len<j_sz)
                    {
                        for(int k=j;k<=j+len;++k)
                        if(matrix[i+len][k]=='0')flag=false;
                    }
                    else flag=false;
                    if(flag)f=true;
                    else dp[i][j]=false;
                }
            }
            if(f)++len;
            else return len*len;
        }
        return len*len;
    }
};
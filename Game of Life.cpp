class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if(!m)return;
        int n=board[0].size();
        for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
        {
            int sum=0;
            if(i-1>=0)
            {
                if(j-1>=0)sum+=-board[i-1][j-1]%2;
                sum+=-board[i-1][j]%2;
                if(j+1<n)sum+=-board[i-1][j+1]%2;
            }
            if(i+1<m)
            {
                if(j-1>=0)
                    sum+=board[i+1][j-1];
                sum+=board[i+1][j];
                if(j+1<n)
                    sum+=board[i+1][j+1];
            }
            if(j-1>=0)
                sum+=-board[i][j-1]%2;
            if(j+1<n)
                sum+=board[i][j+1];
            if(board[i][j])
            {
                if(sum<2 || sum>3)
                    board[i][j]=-3;
                else
                    board[i][j]=-1;
            }
            else if(sum==3)
                board[i][j]=-2;
            else
                board[i][j]=-4;
        }
        
        for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(board[i][j]<-2)
                board[i][j]=0;
            else
                board[i][j]=1;
    }
};
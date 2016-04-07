class Solution {
public:

    bool recur(vector<vector<char>>& board, string word,int i,int j,int &maxi,int &maxj)
    {
        if(!word.size())
            return true;
        if(i>=maxi || j>=maxj || j<0 || i<0)
            return false;
        char temp=word[0];
        if(temp==board[i][j])
        {
            board[i][j]='0';
            if(recur(board,word.substr(1),i+1,j,maxi,maxj)||
            recur(board,word.substr(1),i-1,j,maxi,maxj)||
            recur(board,word.substr(1),i,j-1,maxi,maxj)||
            recur(board,word.substr(1),i,j+1,maxi,maxj))
                return true;
            board[i][j]=temp;
        }
           return false;
    }




    bool exist(vector<vector<char>>& board, string word) {
        int maxi=board.size();
        int maxj=board[0].size();
        if(maxi==0 || maxj==0 )
            return true;
        for(int i=0;i<maxi;i++)
        for(int j=0;j<maxj;j++)
            if(recur(board,word,i,j,maxi,maxj))
                return true;
        return false;
    }
};
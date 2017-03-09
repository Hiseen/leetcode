class Solution {
 public:
 
     int adjacentmine(vector<vector<char>>& board,int i,int j,int size1,int size2)
     {
         int res=0;
         for(int n=i-1;n<=i+1;++n)
             for(int k=j-1;k<=j+1;++k)
                 if(k>=0 && n>=0 && k<size2 && n<size1 && (n!=i || k!=j) && board[n][k]=='M')
                     res+=1;
         return res;
     }
 
 
     void recur(vector<vector<char>>& board,bool** flag,int i,int j,int size1,int size2)
     {
         if(flag[i][j])return;
         flag[i][j]=true;
         int adjacent=adjacentmine(board,i,j,size1,size2);
         if(adjacent)
         {
             board[i][j]=adjacent+'0';
         }
         else
         {
             board[i][j]='B';
             bool a=i-1>=0;
             bool b=j-1>=0;
             bool c=j+1<size2;
             bool d=i+1<size1;
             if(a)recur(board,flag,i-1,j,size1,size2);
             if(b)recur(board,flag,i,j-1,size1,size2);
             if(c)recur(board,flag,i,j+1,size1,size2);
             if(d)recur(board,flag,i+1,j,size1,size2);
             if(a&&b)recur(board,flag,i-1,j-1,size1,size2);
             if(a&&c)recur(board,flag,i-1,j+1,size1,size2);
             if(d&&c)recur(board,flag,i+1,j+1,size1,size2);
             if(d&&b)recur(board,flag,i+1,j-1,size1,size2);
         }
     }
 
     vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
         if(board[click[0]][click[1]]=='M')
         {
             board[click[0]][click[1]]='X';
             return board;
         }
         int size1=board.size();
         int size2=board[0].size();
         bool** flag=new bool*[size1];
         for(int i=0;i<size1;++i)
             flag[i]=new bool[size2];
         for(int i=0;i<size1;++i)
             for(int j=0;j<size2;++j)
                 flag[i][j]=false;
         
         
         recur(board,flag,click[0],click[1],size1,size2);
         for(int i=0;i<size1;++i)
             delete[] flag[i];
         delete[] flag;
         return board;
         
         
     }
 };
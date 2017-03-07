class Solution {
 public:
     int countBattleships(vector<vector<char>>& board) {
         vector<bool> vert;
         int size1=board.size();
         int size2=board[0].size();
         if(size1==1 && size2==1)
             return board[0][0]=='X'?1:0;
         vert.resize(size2,false);
         int res=0;
         int now=false;
         for(int i=0;i<size1;++i)
         {
             now=false;
             for(int j=0;j<size2;++j)
             {
                 if(board[i][j]=='X' && i+1<size1 && board[i+1][j]=='X')
                     vert[j]=true;
                 else if(board[i][j]=='.' && vert[j])
                 {
                     ++res;
                     vert[j]=false;
                 }
                 else if(!vert[j] && board[i][j]=='X' && !now)
                     now=true;
                 if(board[i][j]=='.' && now)
                 {
                     ++res;
                     now=false;
                 }
             }
             if(now)++res;
         }
         for(bool i:vert)
             if(i)++res;
         return res;
         
     }
 };
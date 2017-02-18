class Solution {
 public:
     int islandPerimeter(vector<vector<int>>& grid) {
         int result=0;
         bool lastone=false;
         int size1=grid.size(),size2=grid[0].size();
         for(int i=0;i<size1;++i)
         {
             for(int j=0;j<size2;++j)
             if(grid[i][j])
             {
                 bool temp=i!=0 && grid[i-1][j];
                 if(lastone && temp);
                 else if(lastone)result+=2;
                 else if(temp)result+=2;
                 else result+=4;
                 lastone=true;
             }
             else
                 lastone=false;
             lastone=false;
         }
         return result;
     }
 };
class Solution {
 public:
     int minPathSum(vector<vector<int>>& grid) {
         int h=grid.size(),w=grid[0].size();
         for(int i=1;i<h;i++)
             grid[i][0]+=grid[i-1][0];
         for(int j=1;j<w;j++)
         {
             grid[0][j]+=grid[0][j-1];
             for(int i=1;i<h;i++)
                 grid[i][j]+=std::min(grid[i-1][j],grid[i][j-1]);
         }
         return grid[h-1][w-1];
     }
 };
class Solution {
public:

    void recur(int i, int j,vector<vector<char>>& grid)
    {
        if(i+1<grid.size() && grid[i+1][j]=='1')
        {
            grid[i+1][j]='0';
            recur(i+1,j,grid);
        }
        if(i-1>=0 && grid[i-1][j]=='1')
        {
            grid[i-1][j]='0';
            recur(i-1,j,grid);
        }
        if(j+1<grid[i].size() && grid[i][j+1]=='1')
        {
            grid[i][j+1]='0';
            recur(i,j+1,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1')
        {
            grid[i][j-1]='0';
            recur(i,j-1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();++i)
        for(int j=0;j<grid[i].size();++j)
        {
            if(grid[i][j]=='1')
            {
                count+=1;
                recur(i,j,grid);
            }
        }
        return count;
    }
};
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.


class Solution {
public:
     void dfs(vector<vector<char>>& grid,int i,int j,int rows,int col)
    {
        if(i<0 || j<0 || i>=rows ||j>=col || grid[i][j]!='1')
        return;
        grid[i][j]='2';
        dfs(grid,i+1,j,rows,col);//down
        dfs(grid,i,j+1,rows,col);//right
        dfs(grid,i-1,j,rows,col);//up
        dfs(grid,i,j-1,rows,col);//left
        
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows=grid.size();
        int col=grid[0].size();
        int numberOfIsland=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,rows,col);
                    numberOfIsland+=1;
                }
            }
        }
        return numberOfIsland;
    }
};

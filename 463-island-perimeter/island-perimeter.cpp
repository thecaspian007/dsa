class Solution {
public:
    int dfs(int r,int c, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m)
            return 1;
        if(grid[r][c] == 0)
            return 1;
        if(grid[r][c] == -1)
            return 0;
        grid[r][c] = -1;
        return dfs(r+1,c,grid)
             + dfs(r-1,c,grid)
             + dfs(r,c+1,grid)
             + dfs(r,c-1,grid);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return dfs(i,j,grid);
                }
            }
        }
        return 0;
    }
};
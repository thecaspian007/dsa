class Solution {
public:
    bool dfs(int r,int c, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m)
            return false;
        if(grid[r][c] == 1)
            return true;
        grid[r][c] = 1;
        bool up    = dfs(r+1,c,grid);
        bool down  = dfs(r-1,c,grid);
        bool left  = dfs(r,c-1,grid);
        bool right = dfs(r,c+1,grid);
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(i,j,grid))
                        ans++;
                }
            }
        }
        return ans; 
    }
};
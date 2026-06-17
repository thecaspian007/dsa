class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int oldColor, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        // out of bounds
        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        // not part of component
        if(image[r][c] != oldColor)
            return;

        // already colored
        if(image[r][c] == newColor)
            return;
        image[r][c] = newColor;
        dfs(r+1,c,image,oldColor,newColor);
        dfs(r-1,c,image,oldColor,newColor);
        dfs(r,c+1,image,oldColor,newColor);
        dfs(r,c-1,image,oldColor,newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor != color)
        {
            dfs(sr,sc,image,oldColor,color);
        }
        return image;
    }
};
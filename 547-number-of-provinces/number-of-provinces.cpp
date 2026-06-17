class Solution {
public: 
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& vis)
    {
        vis[city] = 1;
        int n = isConnected.size();
        for(int nei = 0; nei < n; nei++)
        {
            if(isConnected[city][nei] == 1 &&
               !vis[nei])
            {
                dfs(nei, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for(int city = 0; city < n; city++)
        {
            if(!vis[city])
            {
                dfs(city, isConnected, vis);

                provinces++;
            }
        }
        return provinces;
    }
};
class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&visited, int i ,int col)
    {
        visited[i] = col;

        for(auto it: adj[i])
        {
             if(!visited[it])
            {
                if(!dfs(adj, visited, it, !col))
                {
                    return false;
                }
            }
            else if(visited[it] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n+1, 0);

        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }

        for(int i =0; i<n; i++)
        {
            if(!visited[i])
            {
                if(!dfs(adj, visited, i, 0))
                {
                    return false;
                }
            }
        }
          return true;
    }
     
};
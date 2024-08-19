class Solution {
public:
     bool check(vector<vector<int>>& graph, int src, vector<int>& color)
    {
        color[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0;i<graph[u].size();i++)
            {
                if(color[graph[u][i]]==-1)
                {
                    color[graph[u][i]] = !color[u];
                    q.push(graph[u][i]);
                }
                else if(color[graph[u][i]]==color[u])
                {
                    return false;
                }
            }
        }
        return true;   
    }

    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
        vector<int>color(n, -1);
        for(int j=0;j<n;j++)
        {
            if((color[j] == -1) && (check(graph, j, color) == false))
            {
                return false;
            }
        }
        return true;   
    }
};
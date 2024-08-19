class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>&ans,  vector<int>path, int start, int dest)
    {
        path.push_back(start);
        if(start == dest)
        {
            ans.push_back(path);
            return;
        }

        for(auto x: graph[start])
        {
            dfs(graph, ans, path, x,dest);
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;

        int v= graph.size();

        if(v == 0)
        {
            return ans;
        }

        dfs(graph, ans, path, 0, v-1);
        return ans;
    }
};
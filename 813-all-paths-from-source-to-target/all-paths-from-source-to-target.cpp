class Solution {
public:
    vector<vector<int>> answer;

    void dfs(int node, vector<vector<int>>& graph, vector<int>& path)
    {
        path.push_back(node);
        int target = graph.size() - 1;
        if(node == target)
        {
            answer.push_back(path);
            path.pop_back();
            return;
        }
        for(int nei : graph[node])
        {
            dfs(nei, graph, path);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, graph, path);
        return answer;
    }
};
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             int& vertices, int& edges) {

        visited[node] = true;
        vertices++;

        edges += adj[node].size();

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int completeComponents = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                int vertices = 0;
                int edgeCount = 0;

                dfs(i, adj, visited, vertices, edgeCount);

                edgeCount /= 2;

                if (edgeCount == vertices * (vertices - 1) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
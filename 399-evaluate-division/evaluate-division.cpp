class Solution {
private: 
     void dfs(string src, string dst, unordered_map<string, vector<pair<string, double>>>& adj, double& product, unordered_set<string>& visited, double& ans) {
        if (visited.find(src) != visited.end()) {
            return;
        }
        visited.insert(src);
        if (src == dst) {
            ans = product;
            return;
        }

        for (auto it : adj[src]) {
            double val = it.second;
            string v = it.first;
            product *= val;
            dfs(v, dst, adj, product, visited, ans);
            product /= val; 
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int valuesSize = values.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < valuesSize; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> results;
        for (auto it : queries) {
            double product = 1.0;
            double ans = -1.0;
            string src = it[0];
            string dst = it[1];
            unordered_set<string> visited;
            if (adj.find(src) != adj.end()) {
                dfs(src, dst, adj, product, visited, ans);
            }
            results.push_back(ans);
        }
        return results;
    }
};
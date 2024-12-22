class Solution {
public:
    bool dfs(vector<vector<int>>& preList, int node, vector<int>& vis) {
        if (vis[node] == 1)
            return true;

        if (vis[node] == 2)
            return false;

        vis[node] = 1;

        for (int next : preList[node]) {
            if (dfs(preList, next, vis)) {
                return true; 
            }
        }

        vis[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);

        for (const auto& prereq : prerequisites) {
            preList[prereq[0]].push_back(prereq[1]);
        }

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(preList, i, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};
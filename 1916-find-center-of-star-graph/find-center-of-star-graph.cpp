class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();

        if(n == 0)
        {
            return -1;
        }

        map<int, int>mp;
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            mp[u]++;
            mp[v]++;
        }

        for(auto it: mp)
        {
            if(it.second == n)
            {
                return it.first;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==0)
        {
            return -1;
        }
        if(n==1)
        {
            return 1;
        }
        vector<vector<int>>adj(n);
        vector<int>vis(n+1,0);
         map<int, int>mp;
         map<int, int>np;

        for(auto it : trust)
        {
            int u = it[0];
            int v= it[1];
            mp[v]++;
            np[u]++;
        }

       
        for(auto it: mp)
        {
            if(it.second == n-1 && !np[it.first])
            {
                return it.first;
            }
        }
        return -1;
    }
};
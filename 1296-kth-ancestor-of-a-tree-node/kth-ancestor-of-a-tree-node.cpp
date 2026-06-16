class TreeAncestor {
public:
    static const int LOG = 16;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {
        up.assign(n, vector<int>(LOG + 1, -1));
        for(int node = 0; node < n; node++)
        {
            up[node][0] = parent[node];
        }
        for(int j = 1; j <= LOG; j++)
        {
            for(int node = 0; node < n; node++)
            {
                int mid = up[node][j - 1];
                if(mid != -1)
                {
                    up[node][j] = up[mid][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j <= LOG; j++)
        {
            if(node == -1)
                return -1;

            if(k & (1 << j))
            {
                node = up[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int,int>> dir={
            {-2,-1},{-2,1},
            {-1,-2},{-1,2},
            {1,-2},{1,2},
            {2,-1},{2,1}
        };
        vector<vector<double>> prev(n,vector<double>(n,1));
        vector<vector<double>> curr(n,vector<double>(n));
        for(int move=1;move<=k;move++)
        {
            for(int r=0;r<n;r++)
            {
                for(int c=0;c<n;c++)
                {
                    curr[r][c]=0;
                    for(auto &d:dir)
                    {
                        int nr=r+d.first;
                        int nc=c+d.second;
                        if(nr>=0 && nr<n && nc>=0 && nc<n)
                            curr[r][c]+=prev[nr][nc];
                    }
                    curr[r][c]/=8.0;
                }
            }
            prev=curr;
        }
        return prev[row][column];
    }
};
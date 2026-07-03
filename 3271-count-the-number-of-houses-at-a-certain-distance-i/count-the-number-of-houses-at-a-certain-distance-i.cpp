class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                int d1 = abs(i-j);
                int d2 = abs(i-x)+1+abs(j-y);
                int d3 = abs(i-y)+1+abs(j-x);
                int d = min({d1,d2,d3});
                ans[d-1]++;
            }
        }
        return ans;
    }
};
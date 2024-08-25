class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int len = prices.size();

       if(len == 0)
       {
        return 0;
       }

       int maxi = 0;
       int minVal = prices[0];

       for(int i = 0; i<len; i++)
       {
        maxi = max(maxi, prices[i] - minVal);
        minVal = min(minVal, prices[i]);

        if(maxi <0)
        {
            maxi = 0;
        }
       }
       return maxi;
    }
};
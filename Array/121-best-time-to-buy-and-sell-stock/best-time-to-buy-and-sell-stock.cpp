class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      if(len == 0)
      {
        return -1;
      }

      int minVal = prices[0];
      int maxProfit = 0;

      for(int i = 1; i<len; i++)
      {
        maxProfit = max(maxProfit, prices[i] - minVal);
        minVal = min(minVal, prices[i]);
      }
      return maxProfit;
    }
};
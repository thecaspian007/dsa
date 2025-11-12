class Solution {
public:
    int maxProfit(vector<int>& prices) {
     if(prices.size() == 0){
        return 0;
     }
     int minPrice = prices[0];
     int currMax = 0;
     for(int i = 1; i<prices.size(); i++) {
        int diff = prices[i] - minPrice;
        minPrice = min(prices[i], minPrice);
        currMax = max(currMax, diff);
     }
     return currMax;
    }
};
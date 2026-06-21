class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if(costs.size() == 0){
            return 0;
        }
        int count = 0;
        sort(costs.begin(), costs.end());
        int remainCoins = coins;
        for(int i = 0; i<costs.size(); i++){
            if (remainCoins >= costs[i]){
                remainCoins = remainCoins - costs[i];
                count++;
            } 
        }
        return count;
    }
};
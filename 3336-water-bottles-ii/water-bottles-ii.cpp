class Solution {
public:
    int exchange(int numBottles, int numExchange){
        if (numBottles<numExchange) return 0;
        return 1+exchange(numBottles-numExchange+1, numExchange+1);
    }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles+exchange(numBottles, numExchange);
    }
};
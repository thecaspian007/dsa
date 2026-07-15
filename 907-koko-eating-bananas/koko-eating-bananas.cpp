class Solution {
public:
    int maxEle(vector<int>& piles){
        int maxVal = INT_MIN;
        for (int i = 0; i<piles.size(); i++){
            maxVal = max(maxVal, piles[i]);
        }
        return maxVal;
    }

    long long calTotal(vector<int>& piles, int h){
        long long total = 0;
        for(int i = 0; i< piles.size(); i++){
            total += ceil(double(piles[i])/double(h));
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high=maxEle(piles);
        while(low<=high){
            int mid = low + (high - low)/2;
            long long totalH = calTotal(piles, mid);
            if(totalH <= h){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
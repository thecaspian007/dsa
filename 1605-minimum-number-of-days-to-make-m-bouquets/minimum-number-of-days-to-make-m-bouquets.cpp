class Solution {
public:
    int minEle(vector<int>& bloomDay){
        int minVal = INT_MAX;
        for(int i = 0; i < bloomDay.size(); i++){
            minVal = min(minVal, bloomDay[i]);
        }
        return minVal;
    }

    int maxEle(vector<int>& bloomDay){
        int maxVal = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            maxVal = max(maxVal, bloomDay[i]);
        }
        return maxVal;
    }

    int calBouquets(vector<int>& bloomDay, int day, int k){
        int bouquets = 0;
        int flowers = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                flowers++;

                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
       long long requiredFlowers = 1LL * m * k;

        if(requiredFlowers > bloomDay.size()){
            return -1;
        }

        int low = minEle(bloomDay);
        int high = maxEle(bloomDay);

        while(low <= high){
            int mid = low + (high - low) / 2;

            int bouquets = calBouquets(bloomDay, mid, k);

            if(bouquets >= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low; 
    }
};
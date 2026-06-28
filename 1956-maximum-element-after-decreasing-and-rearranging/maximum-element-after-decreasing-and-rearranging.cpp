class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        long long len = arr.size();
        if(len == 0){
            return -1;
        }
        if(len == 1){
            return 1;
        }
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int maxVal = 1;
        for(int i = 1; i<len; i++){
            if(abs(arr[i] - arr[i-1]) <= 1){
                maxVal = max(maxVal, arr[i]);
                continue;
            } 
            arr[i] = arr[i-1] + 1;
            maxVal = max(maxVal, arr[i]);
        }
        return maxVal;
    }
};
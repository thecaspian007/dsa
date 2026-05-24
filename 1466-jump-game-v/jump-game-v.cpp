class Solution {
public:
    int dfs(int i, int d, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for(int j = i+1; j<= min(n-1, i+d); j++){
            if(arr[j] >= arr[i]){
                break;
            }
            ans = max(ans, 1+dfs(j, d, arr, dp));
        }

        for(int j = i-1; j>= max(0, i-d); j--){
            if(arr[j] >= arr[i]){
                break;
            }
            ans = max(ans, 1+dfs(j, d, arr, dp));
        }
        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int len = arr.size();
        vector<int>dp(len, -1);
        int result = 1;
        for(int i = 0; i<len; i++){
            result = max(result, dfs(i, d, arr, dp));
        }
        return result;
    }
};
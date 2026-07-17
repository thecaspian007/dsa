class Solution {
public:
     bool canDistribute(vector<int>& quantities, int n, int maxProducts) {
        long long stores = 0;
        for (int quantity : quantities) {
            stores += (quantity + maxProducts - 1) / maxProducts;
            if (stores > n)
                return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(quantities, n, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
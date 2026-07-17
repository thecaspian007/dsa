class Solution {
public:
    int countLessEqual(int m, int n, int val) {
        int count = 0;
        for (int row = 1; row <= m; row++) {
            count += min(val / row, n);
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(m, n, mid) >= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
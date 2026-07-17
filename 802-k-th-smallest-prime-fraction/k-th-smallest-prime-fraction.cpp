class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0;
        double high = 1.0;
        while (true) {
            double mid = (low + high) / 2.0;
            int count = 0;
            int numerator = 0;
            int denominator = 1;
            int i = 0;
            for (int j = 1; j < n; j++) {
                while (i < j && arr[i] <= mid * arr[j])
                    i++;
                count += i;
                if (i > 0 &&
                    numerator * arr[j] < denominator * arr[i - 1]) {
                    numerator = arr[i - 1];
                    denominator = arr[j];
                }
            }
            if (count == k)
                return {numerator, denominator};
            if (count < k)
                low = mid;
            else
                high = mid;
        }
    }
};
class Solution {
public:
    int maxProduct(int n) {
        if(n == 0){
            return 0;
        }
        int first = -1, second = -1;
        while (n > 0) {
            int digit = n % 10;
            if (digit >= first) {
                second = first;
                first = digit;
            } 
            else if (digit > second) {
                second = digit;
            }
            n /= 10;
        }
        return first * second;
    }
};
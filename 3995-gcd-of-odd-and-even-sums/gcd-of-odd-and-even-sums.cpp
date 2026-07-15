class Solution {
public:
    int sumEvens(int n){
        int val = 2;
        int sum = val;
        while(n>1){
            val += 2;
            sum +=val;
            n--;
        }
        return sum;
    }

    int sumOdds(int n){
        int val = 1;
        int sum = val;
        while(n>1){
            val += 2;
            sum +=val;
            n--;
        }
        return sum;
    }

    int gcdOfOddEvenSums(int n) {
        if(n == 0){
            return 0;
        }
        int odds = sumOdds(n);
        int evens = sumEvens(n);
        return gcd(odds, evens);
    }
};
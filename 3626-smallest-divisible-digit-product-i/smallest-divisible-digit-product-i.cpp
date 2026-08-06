class Solution {
public:
    int product(int n)
    {
        int pdt = 1;
        if (n==0){
            return 0;
        }
        while(n>0){
            int val = n % 10;
            pdt = pdt * val;
            n = n/10;
        }
        return pdt;
    }
    int smallestNumber(int n, int t) {
        if(t == 0){
            return -1;
        }
        if(n == 0){
            return 0;
        }
        for(int i = n; i<=100; i++){
            int pdt = product(i);
            if(pdt % t == 0) {
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool isHappy(int n) {
    unordered_set<int> seen;
    int sum = 0;

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        sum = 0;

        while (n > 0) {
            int val = n % 10;
            sum += val * val;
            n = n / 10;
        }

        n = sum;
    }

    return n == 1;
    }
};
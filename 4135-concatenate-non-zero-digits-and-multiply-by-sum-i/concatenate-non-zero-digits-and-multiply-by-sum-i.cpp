class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0){
            return 0;
        }
        vector<int> fragments;
        while(n>0){
            fragments.push_back(n%10);
            n = n/10;
        }
        long long sum = 0, val = 0;
        reverse(fragments.begin(), fragments.end());
        for(int i = 0; i<fragments.size(); i++){
            if(fragments[i] == 0){
                continue;
            }
            sum = sum + fragments[i];
            val = val*10 + fragments[i];

        }
        return val *sum;
    }
};
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int len = asteroids.size();
        if(len == 0){
            true;
        }
        sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for(int i = 0; i<len; i++){
            if(sum < asteroids[i]){
                return false;
            }
            sum += asteroids[i];
        }
        return true;
    }
};
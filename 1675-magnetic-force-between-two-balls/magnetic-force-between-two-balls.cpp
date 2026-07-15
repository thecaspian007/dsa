class Solution {
public:
    int calBalls(vector<int>& position, int dist){
        int balls = 1;
        int lastPosition = position[0];
        for(int i = 1; i < position.size(); i++){

            if(position[i] - lastPosition >= dist){
                balls++;
                lastPosition = position[i];
            }

        }
        return balls;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[position.size() - 1] - position[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            int balls = calBalls(position, mid);
            if(balls >= m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};
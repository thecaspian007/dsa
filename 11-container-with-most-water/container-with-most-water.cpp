class Solution {
public:
    int maxArea(vector<int>& height) {
        int currentMax = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int width = right - left;
            int heightY = min(height[left], height[right]);
            int currentArea = width * heightY;
            currentMax = max(currentMax, currentArea);

            if(height[left] < height[right]) {
                left++;
            } else{
                right--;
            }
        }
        return currentMax;
    }
};
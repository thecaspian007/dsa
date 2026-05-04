class Solution {
public:
    int maxArea(vector<int>& height) {
        int currMax = 0, area = 0;
        int left = 0, right= height.size()-1;

        while(left<right){
            int width = right-left;
            int minHeight = min(height[left], height[right]);
            area = width*minHeight;
            currMax = max(currMax, area);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return currMax;
    }
};
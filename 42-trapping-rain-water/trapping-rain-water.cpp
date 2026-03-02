class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int left = 0, right = height.size()-1;
        int leftMax = height[left], rightMax=height[right];
        int count = 0;
        while(left<right){
            if(leftMax<rightMax) {
                left++;
                if(height[left]>=leftMax){
                    leftMax = height[left];
                } else {
                    count += leftMax - height[left];
                }
            } else {
                right--;
                if(height[right]>=rightMax){
                    rightMax = height[right];
                } else {
                    count += rightMax - height[right];
                }
            }
        }
        return count;
    }
};
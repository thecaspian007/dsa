class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ans=0;

        while(start<= end)
        {
            int current = min(height[start], height[end]) * (end - start);
            ans = max(ans, current);
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        if(nums.size() == 0)
        {
            return 0;
        }

        for(int i = 0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        while(k>1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>>pq;
        // vector<int>ans;

         for (int j =0; j<m; j++)
            {
                // if(nums1[j] != 0)
                // {
                     pq.push(nums1[j]);
                // }
               
            }
        for (int j =0; j<n; j++)
            {
                // if(nums2[j] != 0)
                // {
                     pq.push(nums2[j]);
                // }
            }
        int i = 0;
        while(pq.size() >0)
        {
            nums1[i] = pq.top();
            pq.pop();
            i++;
        }
    }
};
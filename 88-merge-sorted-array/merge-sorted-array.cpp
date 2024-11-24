class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       if(n== 0 && m!= 0)
       {
        return;
       }
       else if(n != 0 && m == 0)
       {
        int i = 0;
        while(n !=0)
        {
        nums1[i] = nums2[i];
        i++;
        n--;
        }
       }
       
       int last1 = m-1;
       int last2 = n-1;
       int index = m+n-1;

       while(last2 >= 0)
       {
        if(last1 >=0 && nums1[last1] > nums2[last2])
        {
            nums1[index] = nums1[last1];
            last1--;
        }
        else
        {
            nums1[index] = nums2[last2];
            last2--;
        }
        index--;
       }
       
    }
};